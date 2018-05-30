/**************************************************************************************
Copyright 2015 Applied Research Associates, Inc.
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the License
at:
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under
the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
**************************************************************************************/


#pragma once

#if defined(__clang__)
#define BIOGEARS_JNI_API
#elif defined(__gnu_linux__)
#define BIOGEARS_JNI_API __attribute__ ((visibility ("default")))
#else
#ifdef biogears_jni_EXPORTS
#define BIOGEARS_JNI_API __declspec(dllexport)
#else
#define BIOGEARS_JNI_API __declspec(dllimport)
#endif
#endif