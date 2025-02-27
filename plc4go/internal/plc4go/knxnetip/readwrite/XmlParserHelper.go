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

package readwrite

import (
	"github.com/apache/plc4x/plc4go/internal/plc4go/knxnetip/readwrite/model"
	"github.com/apache/plc4x/plc4go/internal/plc4go/spi/utils"
	"github.com/pkg/errors"
	"strconv"
	"strings"
)

// Code generated by code-generation. DO NOT EDIT.

type KnxnetipXmlParserHelper struct {
}

// Temporary imports to silent compiler warnings (TODO: migrate from static to emission based imports)
func init() {
	_ = strconv.ParseUint
	_ = strconv.ParseInt
	_ = strings.Join
	_ = utils.Dump
}

func (m KnxnetipXmlParserHelper) Parse(typeName string, xmlString string, parserArguments ...string) (interface{}, error) {
	switch typeName {
	case "HPAIControlEndpoint":
		return model.HPAIControlEndpointParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "TunnelingResponseDataBlock":
		return model.TunnelingResponseDataBlockParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "DeviceDescriptorType2":
		return model.DeviceDescriptorType2Parse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "ChannelInformation":
		return model.ChannelInformationParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "DeviceConfigurationAckDataBlock":
		return model.DeviceConfigurationAckDataBlockParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "ConnectionRequestInformation":
		return model.ConnectionRequestInformationParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "Apdu":
		parsedUint0, err := strconv.ParseUint(parserArguments[0], 10, 8)
		if err != nil {
			return nil, err
		}
		dataLength := uint8(parsedUint0)
		return model.ApduParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)), dataLength)
	case "HPAIDiscoveryEndpoint":
		return model.HPAIDiscoveryEndpointParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "ProjectInstallationIdentifier":
		return model.ProjectInstallationIdentifierParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "ServiceId":
		return model.ServiceIdParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "HPAIDataEndpoint":
		return model.HPAIDataEndpointParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "RelativeTimestamp":
		return model.RelativeTimestampParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "CEMI":
		parsedUint0, err := strconv.ParseUint(parserArguments[0], 10, 8)
		if err != nil {
			return nil, err
		}
		size := uint8(parsedUint0)
		return model.CEMIParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)), size)
	case "KnxNetIpMessage":
		return model.KnxNetIpMessageParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "DeviceStatus":
		return model.DeviceStatusParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "IPAddress":
		return model.IPAddressParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "GroupObjectDescriptorRealisationTypeB":
		return model.GroupObjectDescriptorRealisationTypeBParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "CEMIAdditionalInformation":
		return model.CEMIAdditionalInformationParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "ComObjectTable":
		firmwareType := model.FirmwareTypeByName(parserArguments[0])
		return model.ComObjectTableParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)), firmwareType)
	case "KnxAddress":
		return model.KnxAddressParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "ConnectionResponseDataBlock":
		return model.ConnectionResponseDataBlockParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "TunnelingRequestDataBlock":
		return model.TunnelingRequestDataBlockParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "DIBDeviceInfo":
		return model.DIBDeviceInfoParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "DeviceConfigurationRequestDataBlock":
		return model.DeviceConfigurationRequestDataBlockParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "DIBSuppSvcFamilies":
		return model.DIBSuppSvcFamiliesParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "LDataFrame":
		return model.LDataFrameParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "ApduDataExt":
		parsedUint0, err := strconv.ParseUint(parserArguments[0], 10, 8)
		if err != nil {
			return nil, err
		}
		length := uint8(parsedUint0)
		return model.ApduDataExtParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)), length)
	case "ApduControl":
		return model.ApduControlParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "KnxGroupAddress":
		parsedUint0, err := strconv.ParseUint(parserArguments[0], 10, 2)
		if err != nil {
			return nil, err
		}
		numLevels := uint8(parsedUint0)
		return model.KnxGroupAddressParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)), numLevels)
	case "GroupObjectDescriptorRealisationType6":
		return model.GroupObjectDescriptorRealisationType6Parse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "GroupObjectDescriptorRealisationType7":
		return model.GroupObjectDescriptorRealisationType7Parse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "MACAddress":
		return model.MACAddressParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "GroupObjectDescriptorRealisationType2":
		return model.GroupObjectDescriptorRealisationType2Parse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	case "ApduData":
		parsedUint0, err := strconv.ParseUint(parserArguments[0], 10, 8)
		if err != nil {
			return nil, err
		}
		dataLength := uint8(parsedUint0)
		return model.ApduDataParse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)), dataLength)
	case "GroupObjectDescriptorRealisationType1":
		return model.GroupObjectDescriptorRealisationType1Parse(utils.NewXmlReadBuffer(strings.NewReader(xmlString)))
	}
	return nil, errors.Errorf("Unsupported type %s", typeName)
}
