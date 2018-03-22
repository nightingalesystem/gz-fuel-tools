/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_FUEL_TOOLS_REST_HH_
#define IGNITION_FUEL_TOOLS_REST_HH_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "ignition/fuel_tools/Export.hh"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif
#include "ignition/fuel_tools/REST.hh"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

namespace ignition
{
  namespace fuel_tools
  {
    /// \brief Stores a response to a RESTful request
    struct IGNITION_FUEL_TOOLS_VISIBLE RestResponse
    {
      /// \brief The returned status code. E.g.: 200
      public: int statusCode = 0;

      /// \brief The data received.
      public: std::string data = "";
    };

    /// \brief the types of HTTP methods
    enum class HttpMethod
    {
      /// \brief Get method.
      GET,

      /// \brief Post method.
      POST,

      /// \brief Delete method.
      DELETE,

      /// \brief Put method.
      PUT,

      /// \brief Patch method.
      PATCH,

      /// \brief Patch method.
      POST_FORM
    };

    /// \brief A helper class for making REST requests.
    class IGNITION_FUEL_TOOLS_VISIBLE Rest
    {
      /// \brief Default constructor.
      public: Rest() = default;

      /// \brief Trigger a REST request.
      /// \param[in] _method The HTTP method. Use all uppercase letters.
      ///            E.g.: "GET"
      /// \param[in] _url The url to request.
      ///            E.g.: "http://localhost:8000/"
      /// \param[in] _version The protocol version.
      ///            E.g.: "1.0"
      /// \param[in] _path The path to request.
      ///            E.g.: "collection"
      /// \param[in] _queryStrings All the query strings to be requested.
      ///            E.g.: {"sort=name", "sortdir=1"}
      /// \param[in] _headers All the headers to be included in the HTTP request
      ///            E.g.: {"Accept: application/json"}
      /// \param[in] _data Data to be included in the HTTP request.
      /// \param[in] _form multi-part / form data to be used with
      ///            Method::POST_FORM
      public: virtual RestResponse Request(const HttpMethod _method,
          const std::string &_url,
          const std::string &_version,
          const std::string &_path,
          const std::vector<std::string> &_queryStrings,
          const std::vector<std::string> &_headers,
          const std::string &_data,
          const std::map<std::string, std::string> &_form =
          std::map<std::string, std::string>()) const;
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif
      /// \brief Copy REST constructor.
      /// \param[in] _deprecated REST to copy.
      public: explicit Rest(const REST &_deprecated);

      /// \brief Copy REST operator constructor.
      /// \param[in] _deprecated REST to copy.
      /// \return Reference to this.
      public: Rest &operator=(const REST &_deprecated);
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
    };
  }
}

#endif
