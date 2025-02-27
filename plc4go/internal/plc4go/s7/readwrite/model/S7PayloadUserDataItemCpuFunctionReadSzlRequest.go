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

package model

import (
	"github.com/apache/plc4x/plc4go/internal/plc4go/spi/utils"
	"github.com/pkg/errors"
)

// Code generated by code-generation. DO NOT EDIT.

// The data-structure of this message
type S7PayloadUserDataItemCpuFunctionReadSzlRequest struct {
	SzlId    *SzlId
	SzlIndex uint16
	Parent   *S7PayloadUserDataItem
}

// The corresponding interface
type IS7PayloadUserDataItemCpuFunctionReadSzlRequest interface {
	LengthInBytes() uint16
	LengthInBits() uint16
	Serialize(writeBuffer utils.WriteBuffer) error
}

///////////////////////////////////////////////////////////
// Accessors for discriminator values.
///////////////////////////////////////////////////////////
func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) CpuFunctionType() uint8 {
	return 0x04
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) CpuSubfunction() uint8 {
	return 0x01
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) DataLength() uint16 {
	return 0
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) InitializeParent(parent *S7PayloadUserDataItem, returnCode DataTransportErrorCode, transportSize DataTransportSize) {
	m.Parent.ReturnCode = returnCode
	m.Parent.TransportSize = transportSize
}

func NewS7PayloadUserDataItemCpuFunctionReadSzlRequest(szlId *SzlId, szlIndex uint16, returnCode DataTransportErrorCode, transportSize DataTransportSize) *S7PayloadUserDataItem {
	child := &S7PayloadUserDataItemCpuFunctionReadSzlRequest{
		SzlId:    szlId,
		SzlIndex: szlIndex,
		Parent:   NewS7PayloadUserDataItem(returnCode, transportSize),
	}
	child.Parent.Child = child
	return child.Parent
}

func CastS7PayloadUserDataItemCpuFunctionReadSzlRequest(structType interface{}) *S7PayloadUserDataItemCpuFunctionReadSzlRequest {
	castFunc := func(typ interface{}) *S7PayloadUserDataItemCpuFunctionReadSzlRequest {
		if casted, ok := typ.(S7PayloadUserDataItemCpuFunctionReadSzlRequest); ok {
			return &casted
		}
		if casted, ok := typ.(*S7PayloadUserDataItemCpuFunctionReadSzlRequest); ok {
			return casted
		}
		if casted, ok := typ.(S7PayloadUserDataItem); ok {
			return CastS7PayloadUserDataItemCpuFunctionReadSzlRequest(casted.Child)
		}
		if casted, ok := typ.(*S7PayloadUserDataItem); ok {
			return CastS7PayloadUserDataItemCpuFunctionReadSzlRequest(casted.Child)
		}
		return nil
	}
	return castFunc(structType)
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) GetTypeName() string {
	return "S7PayloadUserDataItemCpuFunctionReadSzlRequest"
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) LengthInBits() uint16 {
	return m.LengthInBitsConditional(false)
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) LengthInBitsConditional(lastItem bool) uint16 {
	lengthInBits := uint16(m.Parent.ParentLengthInBits())

	// Simple field (szlId)
	lengthInBits += m.SzlId.LengthInBits()

	// Simple field (szlIndex)
	lengthInBits += 16

	return lengthInBits
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) LengthInBytes() uint16 {
	return m.LengthInBits() / 8
}

func S7PayloadUserDataItemCpuFunctionReadSzlRequestParse(readBuffer utils.ReadBuffer) (*S7PayloadUserDataItem, error) {
	if pullErr := readBuffer.PullContext("S7PayloadUserDataItemCpuFunctionReadSzlRequest"); pullErr != nil {
		return nil, pullErr
	}

	// Simple Field (szlId)
	if pullErr := readBuffer.PullContext("szlId"); pullErr != nil {
		return nil, pullErr
	}
	szlId, _szlIdErr := SzlIdParse(readBuffer)
	if _szlIdErr != nil {
		return nil, errors.Wrap(_szlIdErr, "Error parsing 'szlId' field")
	}
	if closeErr := readBuffer.CloseContext("szlId"); closeErr != nil {
		return nil, closeErr
	}

	// Simple Field (szlIndex)
	szlIndex, _szlIndexErr := readBuffer.ReadUint16("szlIndex", 16)
	if _szlIndexErr != nil {
		return nil, errors.Wrap(_szlIndexErr, "Error parsing 'szlIndex' field")
	}

	if closeErr := readBuffer.CloseContext("S7PayloadUserDataItemCpuFunctionReadSzlRequest"); closeErr != nil {
		return nil, closeErr
	}

	// Create a partially initialized instance
	_child := &S7PayloadUserDataItemCpuFunctionReadSzlRequest{
		SzlId:    CastSzlId(szlId),
		SzlIndex: szlIndex,
		Parent:   &S7PayloadUserDataItem{},
	}
	_child.Parent.Child = _child
	return _child.Parent, nil
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) Serialize(writeBuffer utils.WriteBuffer) error {
	ser := func() error {
		if pushErr := writeBuffer.PushContext("S7PayloadUserDataItemCpuFunctionReadSzlRequest"); pushErr != nil {
			return pushErr
		}

		// Simple Field (szlId)
		if pushErr := writeBuffer.PushContext("szlId"); pushErr != nil {
			return pushErr
		}
		_szlIdErr := m.SzlId.Serialize(writeBuffer)
		if popErr := writeBuffer.PopContext("szlId"); popErr != nil {
			return popErr
		}
		if _szlIdErr != nil {
			return errors.Wrap(_szlIdErr, "Error serializing 'szlId' field")
		}

		// Simple Field (szlIndex)
		szlIndex := uint16(m.SzlIndex)
		_szlIndexErr := writeBuffer.WriteUint16("szlIndex", 16, (szlIndex))
		if _szlIndexErr != nil {
			return errors.Wrap(_szlIndexErr, "Error serializing 'szlIndex' field")
		}

		if popErr := writeBuffer.PopContext("S7PayloadUserDataItemCpuFunctionReadSzlRequest"); popErr != nil {
			return popErr
		}
		return nil
	}
	return m.Parent.SerializeParent(writeBuffer, m, ser)
}

func (m *S7PayloadUserDataItemCpuFunctionReadSzlRequest) String() string {
	if m == nil {
		return "<nil>"
	}
	buffer := utils.NewBoxedWriteBufferWithOptions(true, true)
	m.Serialize(buffer)
	return buffer.GetBox().String()
}
