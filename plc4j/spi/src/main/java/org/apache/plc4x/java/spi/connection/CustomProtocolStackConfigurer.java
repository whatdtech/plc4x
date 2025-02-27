/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.plc4x.java.spi.connection;

import static org.apache.plc4x.java.spi.configuration.ConfigurationFactory.*;

import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandler;
import io.netty.channel.ChannelPipeline;
import org.apache.plc4x.java.api.listener.EventListener;
import org.apache.plc4x.java.spi.Plc4xNettyWrapper;
import org.apache.plc4x.java.spi.Plc4xProtocolBase;
import org.apache.plc4x.java.spi.configuration.Configuration;
import org.apache.plc4x.java.spi.context.DriverContext;
import org.apache.plc4x.java.spi.generation.Message;
import org.apache.plc4x.java.spi.generation.MessageIO;

import java.util.List;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.ToIntFunction;

/**
 * Builds a Protocol Stack.
 */
public class CustomProtocolStackConfigurer<BASE_PACKET_CLASS extends Message> implements ProtocolStackConfigurer<BASE_PACKET_CLASS> {

    private final Class<BASE_PACKET_CLASS> basePacketClass;
    private final boolean bigEndian;
    private final Function<Configuration, ? extends Plc4xProtocolBase<BASE_PACKET_CLASS>> protocol;
    private final Function<Configuration, ? extends DriverContext> driverContext;
    private final Function<Configuration, ? extends MessageIO<BASE_PACKET_CLASS, BASE_PACKET_CLASS>> protocolIO;
    private final Function<Configuration, ? extends ToIntFunction<ByteBuf>> packetSizeEstimator;
    private final Function<Configuration, ? extends Consumer<ByteBuf>> corruptPacketRemover;
    private final Object[] parserArgs;

    public static <BPC extends Message> CustomProtocolStackBuilder<BPC> builder(Class<BPC> basePacketClass, Function<Configuration, ? extends  MessageIO<BPC, BPC>> messageIo) {
        return new CustomProtocolStackBuilder<>(basePacketClass, messageIo);
    }

    /** Only accessible via Builder */
    CustomProtocolStackConfigurer(Class<BASE_PACKET_CLASS> basePacketClass,
                                  boolean bigEndian,
                                  Object[] parserArgs,
                                  Function<Configuration, ? extends Plc4xProtocolBase<BASE_PACKET_CLASS>> protocol,
                                  Function<Configuration, ? extends DriverContext> driverContext,
                                  Function<Configuration, ? extends MessageIO<BASE_PACKET_CLASS, BASE_PACKET_CLASS>> protocolIO,
                                  Function<Configuration, ? extends ToIntFunction<ByteBuf>> packetSizeEstimator,
                                  Function<Configuration, ? extends Consumer<ByteBuf>> corruptPacketRemover) {
        this.basePacketClass = basePacketClass;
        this.bigEndian = bigEndian;
        this.parserArgs = parserArgs;
        this.protocol = protocol;
        this.driverContext = driverContext;
        this.protocolIO = protocolIO;
        this.packetSizeEstimator = packetSizeEstimator;
        this.corruptPacketRemover = corruptPacketRemover;
    }

    private ChannelHandler getMessageCodec(Configuration configuration) {
        return new GeneratedProtocolMessageCodec<>(basePacketClass, protocolIO.apply(configuration), bigEndian, parserArgs,
            packetSizeEstimator == null ? null : packetSizeEstimator.apply(configuration),
            corruptPacketRemover == null ? null : corruptPacketRemover.apply(configuration));
    }

    /** Applies the given Stack to the Pipeline */
    @Override
    public Plc4xProtocolBase<BASE_PACKET_CLASS> configurePipeline(
        Configuration configuration, ChannelPipeline pipeline, boolean passive, List<EventListener> ignore) {
        pipeline.addLast(getMessageCodec(configuration));
        Plc4xProtocolBase<BASE_PACKET_CLASS> protocol = configure(configuration, this.protocol.apply(configuration));
        DriverContext driverContext = this.driverContext.apply(configuration);
        if (driverContext != null) {
            protocol.setDriverContext(driverContext);
        }
        Plc4xNettyWrapper<BASE_PACKET_CLASS> context = new Plc4xNettyWrapper<>(pipeline, passive, protocol, basePacketClass);
        pipeline.addLast(context);
        return protocol;
    }

    /**
     * Used to Build Instances of {@link SingleProtocolStackConfigurer}.
     *
     * @param <BASE_PACKET_CLASS> Type of Created Message that is Exchanged.
     */
    public static final class CustomProtocolStackBuilder<BASE_PACKET_CLASS extends Message> {

        private final Class<BASE_PACKET_CLASS> basePacketClass;
        private final Function<Configuration, ? extends MessageIO<BASE_PACKET_CLASS, BASE_PACKET_CLASS>> messageIo;
        private Function<Configuration, ? extends DriverContext> driverContext;
        private boolean bigEndian = true;
        private Object[] parserArgs;
        private Function<Configuration, ? extends Plc4xProtocolBase<BASE_PACKET_CLASS>> protocol;
        private Function<Configuration, ? extends ToIntFunction<ByteBuf>> packetSizeEstimator;
        private Function<Configuration, ? extends Consumer<ByteBuf>> corruptPacketRemover;

        public CustomProtocolStackBuilder(Class<BASE_PACKET_CLASS> basePacketClass, Function<Configuration, ? extends MessageIO<BASE_PACKET_CLASS, BASE_PACKET_CLASS>> messageIo) {
            this.basePacketClass = basePacketClass;
            this.messageIo = messageIo;
        }

        public CustomProtocolStackBuilder<BASE_PACKET_CLASS> withDriverContext(Function<Configuration, ? extends DriverContext> driverContextClass) {
            this.driverContext = driverContextClass;
            return this;
        }

        public CustomProtocolStackBuilder<BASE_PACKET_CLASS> littleEndian() {
            this.bigEndian = false;
            return this;
        }

        public CustomProtocolStackBuilder<BASE_PACKET_CLASS> withParserArgs(Object... parserArgs) {
            this.parserArgs = parserArgs;
            return this;
        }

        public CustomProtocolStackBuilder<BASE_PACKET_CLASS> withProtocol(Function<Configuration, ? extends Plc4xProtocolBase<BASE_PACKET_CLASS>> protocol) {
            this.protocol = protocol;
            return this;
        }

        public CustomProtocolStackBuilder<BASE_PACKET_CLASS> withPacketSizeEstimator(Function<Configuration, ? extends ToIntFunction<ByteBuf>> packetSizeEstimator) {
            this.packetSizeEstimator = packetSizeEstimator;
            return this;
        }

        public CustomProtocolStackBuilder<BASE_PACKET_CLASS> withCorruptPacketRemover(Function<Configuration, ? extends Consumer<ByteBuf>> corruptPacketRemover) {
            this.corruptPacketRemover = corruptPacketRemover;
            return this;
        }

        public CustomProtocolStackConfigurer<BASE_PACKET_CLASS> build() {
            assert this.protocol != null;
            return new CustomProtocolStackConfigurer<>(
                basePacketClass, bigEndian, parserArgs, protocol, driverContext, messageIo, packetSizeEstimator, corruptPacketRemover);
        }

    }

}
