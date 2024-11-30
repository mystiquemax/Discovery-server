// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file data_type.cpp
 * This source file contains the implementation of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "data_type.h"

#include <fastcdr/Cdr.h>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>




discovery_server::discovery_server()
{
}

discovery_server::~discovery_server()
{
}

discovery_server::discovery_server(
        const discovery_server& x)
{
    m_id = x.m_id;
    m_msg = x.m_msg;
}

discovery_server::discovery_server(
        discovery_server&& x) noexcept
{
    m_id = x.m_id;
    m_msg = std::move(x.m_msg);
}

discovery_server& discovery_server::operator =(
        const discovery_server& x)
{

    m_id = x.m_id;
    m_msg = x.m_msg;
    return *this;
}

discovery_server& discovery_server::operator =(
        discovery_server&& x) noexcept
{

    m_id = x.m_id;
    m_msg = std::move(x.m_msg);
    return *this;
}

bool discovery_server::operator ==(
        const discovery_server& x) const
{
    return (m_id == x.m_id &&
           m_msg == x.m_msg);
}

bool discovery_server::operator !=(
        const discovery_server& x) const
{
    return !(*this == x);
}

/*!
 * @brief This function sets a value in member id
 * @param _id New value for member id
 */
void discovery_server::id(
        uint32_t _id)
{
    m_id = _id;
}

/*!
 * @brief This function returns the value of member id
 * @return Value of member id
 */
uint32_t discovery_server::id() const
{
    return m_id;
}

/*!
 * @brief This function returns a reference to member id
 * @return Reference to member id
 */
uint32_t& discovery_server::id()
{
    return m_id;
}


/*!
 * @brief This function copies the value in member msg
 * @param _msg New value to be copied in member msg
 */
void discovery_server::msg(
        const std::string& _msg)
{
    m_msg = _msg;
}

/*!
 * @brief This function moves the value in member msg
 * @param _msg New value to be moved in member msg
 */
void discovery_server::msg(
        std::string&& _msg)
{
    m_msg = std::move(_msg);
}

/*!
 * @brief This function returns a constant reference to member msg
 * @return Constant reference to member msg
 */
const std::string& discovery_server::msg() const
{
    return m_msg;
}

/*!
 * @brief This function returns a reference to member msg
 * @return Reference to member msg
 */
std::string& discovery_server::msg()
{
    return m_msg;
}


// Include auxiliary functions like for serializing/deserializing.
#include "data_typeCdrAux.ipp"

