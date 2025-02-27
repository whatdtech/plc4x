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

#include <stdio.h>
#include <plc4c/spi/evaluation_helper.h>
#include "s7_parameter.h"

// Code generated by code-generation. DO NOT EDIT.

// Array of discriminator values that match the enum type constants.
// (The order is identical to the enum constants so we can use the
// enum constant to directly access a given types discriminator values)
const plc4c_s7_read_write_s7_parameter_discriminator plc4c_s7_read_write_s7_parameter_discriminators[] = {
  {/* plc4c_s7_read_write_s7_parameter_setup_communication */
   .parameterType = 0xF0, .messageType = -1 },
  {/* plc4c_s7_read_write_s7_parameter_read_var_request */
   .parameterType = 0x04, .messageType = 0x01 },
  {/* plc4c_s7_read_write_s7_parameter_read_var_response */
   .parameterType = 0x04, .messageType = 0x03 },
  {/* plc4c_s7_read_write_s7_parameter_write_var_request */
   .parameterType = 0x05, .messageType = 0x01 },
  {/* plc4c_s7_read_write_s7_parameter_write_var_response */
   .parameterType = 0x05, .messageType = 0x03 },
  {/* plc4c_s7_read_write_s7_parameter_user_data */
   .parameterType = 0x00, .messageType = 0x07 },
  {/* plc4c_s7_read_write_s7_parameter_mode_transition */
   .parameterType = 0x01, .messageType = 0x07 }

};

// Function returning the discriminator values for a given type constant.
plc4c_s7_read_write_s7_parameter_discriminator plc4c_s7_read_write_s7_parameter_get_discriminator(plc4c_s7_read_write_s7_parameter_type type) {
  return plc4c_s7_read_write_s7_parameter_discriminators[type];
}

// Create an empty NULL-struct
static const plc4c_s7_read_write_s7_parameter plc4c_s7_read_write_s7_parameter_null_const;

plc4c_s7_read_write_s7_parameter plc4c_s7_read_write_s7_parameter_null() {
  return plc4c_s7_read_write_s7_parameter_null_const;
}


// Parse function.
plc4c_return_code plc4c_s7_read_write_s7_parameter_parse(plc4c_spi_read_buffer* readBuffer, uint8_t messageType, plc4c_s7_read_write_s7_parameter** _message) {
  uint16_t startPos = plc4c_spi_read_get_pos(readBuffer);
  uint16_t curPos;
  plc4c_return_code _res = OK;

  // Allocate enough memory to contain this data structure.
  (*_message) = malloc(sizeof(plc4c_s7_read_write_s7_parameter));
  if(*_message == NULL) {
    return NO_MEMORY;
  }
        // Discriminator Field (parameterType)

  // Discriminator Field (parameterType) (Used as input to a switch field)
  uint8_t parameterType = 0;
  _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &parameterType);
  if(_res != OK) {
    return _res;
  }

  // Switch Field (Depending on the discriminator values, passes the instantiation to a sub-type)
  if(parameterType == 0xF0) { /* S7ParameterSetupCommunication */
    (*_message)->_type = plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_setup_communication;
                    
    // Reserved Field (Compartmentalized so the "reserved" variable can't leak)
    {
      uint8_t _reserved = 0;
      _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &_reserved);
      if(_res != OK) {
        return _res;
      }
      if(_reserved != 0x00) {
        printf("Expected constant value '%d' but got '%d' for reserved field.", 0x00, _reserved);
      }
    }


                    
    // Simple Field (maxAmqCaller)
    uint16_t maxAmqCaller = 0;
    _res = plc4c_spi_read_unsigned_short(readBuffer, 16, (uint16_t*) &maxAmqCaller);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_setup_communication_max_amq_caller = maxAmqCaller;


                    
    // Simple Field (maxAmqCallee)
    uint16_t maxAmqCallee = 0;
    _res = plc4c_spi_read_unsigned_short(readBuffer, 16, (uint16_t*) &maxAmqCallee);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_setup_communication_max_amq_callee = maxAmqCallee;


                    
    // Simple Field (pduLength)
    uint16_t pduLength = 0;
    _res = plc4c_spi_read_unsigned_short(readBuffer, 16, (uint16_t*) &pduLength);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_setup_communication_pdu_length = pduLength;

  } else 
  if((parameterType == 0x04) && (messageType == 0x01)) { /* S7ParameterReadVarRequest */
    (*_message)->_type = plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_read_var_request;
                    
    // Implicit Field (numItems) (Used for parsing, but it's value is not stored as it's implicitly given by the objects content)
    uint8_t numItems = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &numItems);
    if(_res != OK) {
      return _res;
    }


                    
    // Array field (items)
    plc4c_list* items = NULL;
    plc4c_utils_list_create(&items);
    if(items == NULL) {
      return NO_MEMORY;
    }
    {
      // Count array
      uint16_t itemCount = (uint16_t) numItems;
      for(int curItem = 0; curItem < itemCount; curItem++) {
        bool lastItem = curItem == (itemCount - 1);
        plc4c_s7_read_write_s7_var_request_parameter_item* _value = NULL;
        _res = plc4c_s7_read_write_s7_var_request_parameter_item_parse(readBuffer, (void*) &_value);
        if(_res != OK) {
          return _res;
        }
        plc4c_utils_list_insert_head_value(items, _value);
      }
    }
    (*_message)->s7_parameter_read_var_request_items = items;

  } else 
  if((parameterType == 0x04) && (messageType == 0x03)) { /* S7ParameterReadVarResponse */
    (*_message)->_type = plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_read_var_response;
                    
    // Simple Field (numItems)
    uint8_t numItems = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &numItems);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_read_var_response_num_items = numItems;

  } else 
  if((parameterType == 0x05) && (messageType == 0x01)) { /* S7ParameterWriteVarRequest */
    (*_message)->_type = plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_write_var_request;
                    
    // Implicit Field (numItems) (Used for parsing, but it's value is not stored as it's implicitly given by the objects content)
    uint8_t numItems = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &numItems);
    if(_res != OK) {
      return _res;
    }


                    
    // Array field (items)
    plc4c_list* items = NULL;
    plc4c_utils_list_create(&items);
    if(items == NULL) {
      return NO_MEMORY;
    }
    {
      // Count array
      uint16_t itemCount = (uint16_t) numItems;
      for(int curItem = 0; curItem < itemCount; curItem++) {
        bool lastItem = curItem == (itemCount - 1);
        plc4c_s7_read_write_s7_var_request_parameter_item* _value = NULL;
        _res = plc4c_s7_read_write_s7_var_request_parameter_item_parse(readBuffer, (void*) &_value);
        if(_res != OK) {
          return _res;
        }
        plc4c_utils_list_insert_head_value(items, _value);
      }
    }
    (*_message)->s7_parameter_write_var_request_items = items;

  } else 
  if((parameterType == 0x05) && (messageType == 0x03)) { /* S7ParameterWriteVarResponse */
    (*_message)->_type = plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_write_var_response;
                    
    // Simple Field (numItems)
    uint8_t numItems = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &numItems);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_write_var_response_num_items = numItems;

  } else 
  if((parameterType == 0x00) && (messageType == 0x07)) { /* S7ParameterUserData */
    (*_message)->_type = plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_user_data;
                    
    // Implicit Field (numItems) (Used for parsing, but it's value is not stored as it's implicitly given by the objects content)
    uint8_t numItems = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &numItems);
    if(_res != OK) {
      return _res;
    }


                    
    // Array field (items)
    plc4c_list* items = NULL;
    plc4c_utils_list_create(&items);
    if(items == NULL) {
      return NO_MEMORY;
    }
    {
      // Count array
      uint16_t itemCount = (uint16_t) numItems;
      for(int curItem = 0; curItem < itemCount; curItem++) {
        bool lastItem = curItem == (itemCount - 1);
        plc4c_s7_read_write_s7_parameter_user_data_item* _value = NULL;
        _res = plc4c_s7_read_write_s7_parameter_user_data_item_parse(readBuffer, (void*) &_value);
        if(_res != OK) {
          return _res;
        }
        plc4c_utils_list_insert_head_value(items, _value);
      }
    }
    (*_message)->s7_parameter_user_data_items = items;

  } else 
  if((parameterType == 0x01) && (messageType == 0x07)) { /* S7ParameterModeTransition */
    (*_message)->_type = plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_mode_transition;
                    
    // Reserved Field (Compartmentalized so the "reserved" variable can't leak)
    {
      uint16_t _reserved = 0;
      _res = plc4c_spi_read_unsigned_short(readBuffer, 16, (uint16_t*) &_reserved);
      if(_res != OK) {
        return _res;
      }
      if(_reserved != 0x0010) {
        printf("Expected constant value '%d' but got '%d' for reserved field.", 0x0010, _reserved);
      }
    }


                    
    // Implicit Field (itemLength) (Used for parsing, but it's value is not stored as it's implicitly given by the objects content)
    uint8_t itemLength = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &itemLength);
    if(_res != OK) {
      return _res;
    }


                    
    // Simple Field (method)
    uint8_t method = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &method);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_mode_transition_method = method;


                    
    // Simple Field (cpuFunctionType)
    uint8_t cpuFunctionType = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 4, (uint8_t*) &cpuFunctionType);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_mode_transition_cpu_function_type = cpuFunctionType;


                    
    // Simple Field (cpuFunctionGroup)
    uint8_t cpuFunctionGroup = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 4, (uint8_t*) &cpuFunctionGroup);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_mode_transition_cpu_function_group = cpuFunctionGroup;


                    
    // Simple Field (currentMode)
    uint8_t currentMode = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &currentMode);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_mode_transition_current_mode = currentMode;


                    
    // Simple Field (sequenceNumber)
    uint8_t sequenceNumber = 0;
    _res = plc4c_spi_read_unsigned_byte(readBuffer, 8, (uint8_t*) &sequenceNumber);
    if(_res != OK) {
      return _res;
    }
    (*_message)->s7_parameter_mode_transition_sequence_number = sequenceNumber;

  }

  return OK;
}

plc4c_return_code plc4c_s7_read_write_s7_parameter_serialize(plc4c_spi_write_buffer* writeBuffer, plc4c_s7_read_write_s7_parameter* _message) {
  plc4c_return_code _res = OK;

  // Discriminator Field (parameterType)
  plc4c_spi_write_unsigned_byte(writeBuffer, 8, plc4c_s7_read_write_s7_parameter_get_discriminator(_message->_type).parameterType);

  // Switch Field (Depending of the current type, serialize the sub-type elements)
  switch(_message->_type) {
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_setup_communication: {

      // Reserved Field
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, 0x00);
      if(_res != OK) {
        return _res;
      }

      // Simple Field (maxAmqCaller)
      _res = plc4c_spi_write_unsigned_short(writeBuffer, 16, _message->s7_parameter_setup_communication_max_amq_caller);
      if(_res != OK) {
        return _res;
      }

      // Simple Field (maxAmqCallee)
      _res = plc4c_spi_write_unsigned_short(writeBuffer, 16, _message->s7_parameter_setup_communication_max_amq_callee);
      if(_res != OK) {
        return _res;
      }

      // Simple Field (pduLength)
      _res = plc4c_spi_write_unsigned_short(writeBuffer, 16, _message->s7_parameter_setup_communication_pdu_length);
      if(_res != OK) {
        return _res;
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_read_var_request: {

      // Implicit Field (numItems) (Used for parsing, but it's value is not stored as it's implicitly given by the objects content)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, plc4c_spi_evaluation_helper_count(_message->s7_parameter_read_var_request_items));
      if(_res != OK) {
        return _res;
      }

      // Array field (items)
      {
        uint8_t itemCount = plc4c_utils_list_size(_message->s7_parameter_read_var_request_items);
        for(int curItem = 0; curItem < itemCount; curItem++) {
          bool lastItem = curItem == (itemCount - 1);
          plc4c_s7_read_write_s7_var_request_parameter_item* _value = (plc4c_s7_read_write_s7_var_request_parameter_item*) plc4c_utils_list_get_value(_message->s7_parameter_read_var_request_items, curItem);
          _res = plc4c_s7_read_write_s7_var_request_parameter_item_serialize(writeBuffer, (void*) _value);
          if(_res != OK) {
            return _res;
          }
        }
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_read_var_response: {

      // Simple Field (numItems)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, _message->s7_parameter_read_var_response_num_items);
      if(_res != OK) {
        return _res;
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_write_var_request: {

      // Implicit Field (numItems) (Used for parsing, but it's value is not stored as it's implicitly given by the objects content)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, plc4c_spi_evaluation_helper_count(_message->s7_parameter_write_var_request_items));
      if(_res != OK) {
        return _res;
      }

      // Array field (items)
      {
        uint8_t itemCount = plc4c_utils_list_size(_message->s7_parameter_write_var_request_items);
        for(int curItem = 0; curItem < itemCount; curItem++) {
          bool lastItem = curItem == (itemCount - 1);
          plc4c_s7_read_write_s7_var_request_parameter_item* _value = (plc4c_s7_read_write_s7_var_request_parameter_item*) plc4c_utils_list_get_value(_message->s7_parameter_write_var_request_items, curItem);
          _res = plc4c_s7_read_write_s7_var_request_parameter_item_serialize(writeBuffer, (void*) _value);
          if(_res != OK) {
            return _res;
          }
        }
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_write_var_response: {

      // Simple Field (numItems)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, _message->s7_parameter_write_var_response_num_items);
      if(_res != OK) {
        return _res;
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_user_data: {

      // Implicit Field (numItems) (Used for parsing, but it's value is not stored as it's implicitly given by the objects content)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, plc4c_spi_evaluation_helper_count(_message->s7_parameter_user_data_items));
      if(_res != OK) {
        return _res;
      }

      // Array field (items)
      {
        uint8_t itemCount = plc4c_utils_list_size(_message->s7_parameter_user_data_items);
        for(int curItem = 0; curItem < itemCount; curItem++) {
          bool lastItem = curItem == (itemCount - 1);
          plc4c_s7_read_write_s7_parameter_user_data_item* _value = (plc4c_s7_read_write_s7_parameter_user_data_item*) plc4c_utils_list_get_value(_message->s7_parameter_user_data_items, curItem);
          _res = plc4c_s7_read_write_s7_parameter_user_data_item_serialize(writeBuffer, (void*) _value);
          if(_res != OK) {
            return _res;
          }
        }
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_mode_transition: {

      // Reserved Field
      _res = plc4c_spi_write_unsigned_short(writeBuffer, 16, 0x0010);
      if(_res != OK) {
        return _res;
      }

      // Implicit Field (itemLength) (Used for parsing, but it's value is not stored as it's implicitly given by the objects content)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, (plc4c_s7_read_write_s7_parameter_length_in_bytes(_message)) - (2));
      if(_res != OK) {
        return _res;
      }

      // Simple Field (method)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, _message->s7_parameter_mode_transition_method);
      if(_res != OK) {
        return _res;
      }

      // Simple Field (cpuFunctionType)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 4, _message->s7_parameter_mode_transition_cpu_function_type);
      if(_res != OK) {
        return _res;
      }

      // Simple Field (cpuFunctionGroup)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 4, _message->s7_parameter_mode_transition_cpu_function_group);
      if(_res != OK) {
        return _res;
      }

      // Simple Field (currentMode)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, _message->s7_parameter_mode_transition_current_mode);
      if(_res != OK) {
        return _res;
      }

      // Simple Field (sequenceNumber)
      _res = plc4c_spi_write_unsigned_byte(writeBuffer, 8, _message->s7_parameter_mode_transition_sequence_number);
      if(_res != OK) {
        return _res;
      }

      break;
    }
  }

  return OK;
}

uint16_t plc4c_s7_read_write_s7_parameter_length_in_bytes(plc4c_s7_read_write_s7_parameter* _message) {
  return plc4c_s7_read_write_s7_parameter_length_in_bits(_message) / 8;
}

uint16_t plc4c_s7_read_write_s7_parameter_length_in_bits(plc4c_s7_read_write_s7_parameter* _message) {
  uint16_t lengthInBits = 0;

  // Discriminator Field (parameterType)
  lengthInBits += 8;

  // Depending of the current type, add the length of sub-type elements ...
  switch(_message->_type) {
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_setup_communication: {

      // Reserved Field (reserved)
      lengthInBits += 8;


      // Simple field (maxAmqCaller)
      lengthInBits += 16;


      // Simple field (maxAmqCallee)
      lengthInBits += 16;


      // Simple field (pduLength)
      lengthInBits += 16;

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_read_var_request: {

      // Implicit Field (numItems)
      lengthInBits += 8;


      // Array field
      if(_message->s7_parameter_read_var_request_items != NULL) {
        plc4c_list_element* curElement = _message->s7_parameter_read_var_request_items->tail;
        while (curElement != NULL) {
          lengthInBits += plc4c_s7_read_write_s7_var_request_parameter_item_length_in_bits((plc4c_s7_read_write_s7_var_request_parameter_item*) curElement->value);
          curElement = curElement->next;
        }
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_read_var_response: {

      // Simple field (numItems)
      lengthInBits += 8;

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_write_var_request: {

      // Implicit Field (numItems)
      lengthInBits += 8;


      // Array field
      if(_message->s7_parameter_write_var_request_items != NULL) {
        plc4c_list_element* curElement = _message->s7_parameter_write_var_request_items->tail;
        while (curElement != NULL) {
          lengthInBits += plc4c_s7_read_write_s7_var_request_parameter_item_length_in_bits((plc4c_s7_read_write_s7_var_request_parameter_item*) curElement->value);
          curElement = curElement->next;
        }
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_write_var_response: {

      // Simple field (numItems)
      lengthInBits += 8;

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_user_data: {

      // Implicit Field (numItems)
      lengthInBits += 8;


      // Array field
      if(_message->s7_parameter_user_data_items != NULL) {
        plc4c_list_element* curElement = _message->s7_parameter_user_data_items->tail;
        while (curElement != NULL) {
          lengthInBits += plc4c_s7_read_write_s7_parameter_user_data_item_length_in_bits((plc4c_s7_read_write_s7_parameter_user_data_item*) curElement->value);
          curElement = curElement->next;
        }
      }

      break;
    }
    case plc4c_s7_read_write_s7_parameter_type_plc4c_s7_read_write_s7_parameter_mode_transition: {

      // Reserved Field (reserved)
      lengthInBits += 16;


      // Implicit Field (itemLength)
      lengthInBits += 8;


      // Simple field (method)
      lengthInBits += 8;


      // Simple field (cpuFunctionType)
      lengthInBits += 4;


      // Simple field (cpuFunctionGroup)
      lengthInBits += 4;


      // Simple field (currentMode)
      lengthInBits += 8;


      // Simple field (sequenceNumber)
      lengthInBits += 8;

      break;
    }
  }

  return lengthInBits;
}

