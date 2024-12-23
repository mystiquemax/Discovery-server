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
 * @file data_type.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_DATA_TYPE_H_
#define _FAST_DDS_GENERATED_DATA_TYPE_H_

#include <array>
#include <bitset>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <fastcdr/cdr/fixed_size_string.hpp>
#include <fastcdr/xcdr/external.hpp>
#include <fastcdr/xcdr/optional.hpp>



#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(DATA_TYPE_SOURCE)
#define DATA_TYPE_DllAPI __declspec( dllexport )
#else
#define DATA_TYPE_DllAPI __declspec( dllimport )
#endif // DATA_TYPE_SOURCE
#else
#define DATA_TYPE_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define DATA_TYPE_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
class CdrSizeCalculator;
} // namespace fastcdr
} // namespace eprosima





/*!
 * @brief This class represents the structure discovery_server defined by the user in the IDL file.
 * @ingroup data_type
 */
class discovery_server
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport discovery_server();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~discovery_server();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object discovery_server that will be copied.
     */
    eProsima_user_DllExport discovery_server(
            const discovery_server& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object discovery_server that will be copied.
     */
    eProsima_user_DllExport discovery_server(
            discovery_server&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object discovery_server that will be copied.
     */
    eProsima_user_DllExport discovery_server& operator =(
            const discovery_server& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object discovery_server that will be copied.
     */
    eProsima_user_DllExport discovery_server& operator =(
            discovery_server&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x discovery_server object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const discovery_server& x) const;

    /*!
     * @brief Comparison operator.
     * @param x discovery_server object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const discovery_server& x) const;

    /*!
     * @brief This function sets a value in member id
     * @param _id New value for member id
     */
    eProsima_user_DllExport void id(
            uint32_t _id);

    /*!
     * @brief This function returns the value of member id
     * @return Value of member id
     */
    eProsima_user_DllExport uint32_t id() const;

    /*!
     * @brief This function returns a reference to member id
     * @return Reference to member id
     */
    eProsima_user_DllExport uint32_t& id();


    /*!
     * @brief This function copies the value in member msg
     * @param _msg New value to be copied in member msg
     */
    eProsima_user_DllExport void msg(
            const std::string& _msg);

    /*!
     * @brief This function moves the value in member msg
     * @param _msg New value to be moved in member msg
     */
    eProsima_user_DllExport void msg(
            std::string&& _msg);

    /*!
     * @brief This function returns a constant reference to member msg
     * @return Constant reference to member msg
     */
    eProsima_user_DllExport const std::string& msg() const;

    /*!
     * @brief This function returns a reference to member msg
     * @return Reference to member msg
     */
    eProsima_user_DllExport std::string& msg();

private:

    uint32_t m_id{0};
    std::string m_msg;

};

#endif // _FAST_DDS_GENERATED_DATA_TYPE_H_



