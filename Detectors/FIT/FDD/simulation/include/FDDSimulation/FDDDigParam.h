// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file  FDDDigParam.h
/// \brief Configurable digitization parameters
///
/// \author Andreas Molander <andreas.molander@cern.ch>

#ifndef ALICEO2_FDD_DIG_PARAM
#define ALICEO2_FDD_DIG_PARAM

#include "CommonUtils/ConfigurableParamHelper.h"

namespace o2::fdd
{
struct FDDDigParam : o2::conf::ConfigurableParamHelper<FDDDigParam> {
  float hitTimeOffsetA = 0; ///< Hit time offset on the A side [ns]
  float hitTimeOffsetC = 0; ///< Hit time offset on the C side [ns]

  float pmGainA = 5.914e7f; ///< PM gain
  float pmGainC = 5.914e7f; ///< PM gain
  float GainSmearingSigma = 0.35f; // Log-normal PMT gain smearing per hit
  float MaxPhotoelectronDelay = 20.f; // ns; discard photoelectrons sampled above this delay
  float TimeOffsetCFD = -170.f; // CFD time offset in TDC units
  float TimeSmearingSigma = 1.f; // ns
  float CFDThreshold = 3.f; // mV, assuming a 50 Ohm input; <= 0 disables the amplitude cut

  int CFDInADCGate = 192; // Half-width in TDC counts; abs(time) must be strictly smaller

  // All window boundaries are strict.
  int OrGate = 255; // TDC counts, Run 3 hardware setting
  int OrTriggerAmplitudeLowThresholdSideA = 6;
  int OrTriggerAmplitudeLowThresholdSideC = 0;
  // Exclusive upper bound that includes the saturated ADC bin (4095).
  int OrTriggerAmplitudeHighThresholdSideA = 4096;
  int OrTriggerAmplitudeHighThresholdSideC = 4096;
  int VtxTriggerTimeWindow = 100; // TDC counts, software trigger in PR #16042
  bool TriggerCoincidenceMode = true;

  O2ParamDef(FDDDigParam, "FDDDigParam");
};
} // namespace o2::fdd

#endif // ALICEO2_FDD_DIG_PARAM
