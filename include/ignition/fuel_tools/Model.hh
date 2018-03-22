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

#ifndef IGNITION_FUEL_TOOLS_MODEL_HH_
#define IGNITION_FUEL_TOOLS_MODEL_HH_

#include <memory>
#include <string>

#include "ignition/fuel_tools/Helpers.hh"
#include "ignition/fuel_tools/Result.hh"
#include "ignition/fuel_tools/ModelIdentifier.hh"


namespace ignition
{
  namespace fuel_tools
  {
    // Forward Declaration
    class ModelPrivate;
    class ModelIter;
    class ModelIterPrivate;
    class LocalCache;
    class LocalCachePrivate;
    class IterIds;
    class IterRESTIds;
    class IterRestIds;
    class ModelIterTest;

    /// \brief Defines how to identify a model
    class IGNITION_FUEL_TOOLS_VISIBLE Model
    {
      friend IterIds;
      friend IterRESTIds;
      friend IterRestIds;
      friend ModelIter;
      friend ModelIterPrivate;
      friend ModelIterTest;
      friend LocalCache;
      friend LocalCachePrivate;

      /// \brief Default constructor
      public: Model();

      /// \brief Protected constructor
      protected: explicit Model(std::shared_ptr<ModelPrivate> _dptr);

      /// \brief Copy constructor
      public: Model(const Model &_orig) = default;

      /// \brief Returns false if model was constructed via Model()
      public: operator bool();

      /// \brief returns information identifying the model
      public: ModelIdentifier Identification();

      /// \brief Make sure this model is in the local cache
      /// \remarks this downloads the model and saves it locally if necessary
      /// \returns The result of fetching
      public: Result Fetch();

      /// \brief returns a path to the model on disk if it is already cached
      /// \returns path, or empty string if the model is not cached.
      public: std::string PathToModel();

      /// \brief PIMPL
      private: std::shared_ptr<ModelPrivate> dataPtr;
    };
  }
}

#endif
