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

#include <biogears/cdm/patient/actions/SEChestOcclusiveDressing.h>

namespace biogears {
SEChestOcclusiveDressing::SEChestOcclusiveDressing()
  : SEPatientAction()
{
  m_State = CDM::enumOnOff::Off;
}

SEChestOcclusiveDressing::~SEChestOcclusiveDressing()
{
  Clear();
}

void SEChestOcclusiveDressing::Clear()
{
  SEPatientAction::Clear();
  m_State = CDM::enumOnOff::Off;
}

bool SEChestOcclusiveDressing::IsValid() const
{
  return SEPatientAction::IsValid();
}

bool SEChestOcclusiveDressing::IsActive() const
{
  return IsValid() && m_State == CDM::enumOnOff::On;
}

void SEChestOcclusiveDressing::SetActive(bool b)
{
  m_State = b ? CDM::enumOnOff::On : CDM::enumOnOff::Off;
}

bool SEChestOcclusiveDressing::Load(const CDM::ChestOcclusiveDressingData& in)
{
  SEPatientAction::Load(in);
  m_State = in.State();
  return true;
}

CDM::ChestOcclusiveDressingData* SEChestOcclusiveDressing::Unload() const
{
  CDM::ChestOcclusiveDressingData* data(new CDM::ChestOcclusiveDressingData());
  Unload(*data);
  return data;
}

void SEChestOcclusiveDressing::Unload(CDM::ChestOcclusiveDressingData& data) const
{
  SEPatientAction::Unload(data);
  data.State(m_State);
}
void SEChestOcclusiveDressing::ToString(std::ostream& str) const
{
  str << "Patient Action : Chest Occlusive Dressing";
  if (HasComment())
    str << "\n\tComment: " << m_Comment;
  str << "\n\tState: " << IsActive();
  str << std::flush;
}
}