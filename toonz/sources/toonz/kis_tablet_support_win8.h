/*
* This file is based on the Windows Pointer Input Message support code files by
* Alvin Wong.
* Notwithstanding the license specified in this repository, this file is
* redistributed under BSD 2-Clause license written below in order to keep
* backporting available.
*
* All contributions by Alvin Wong:
* Copyright (c) 2017 Alvin Wong <alvinhochun@gmail.com>
* All rights reserved.
*
* All other contributions:
* Copyright (c) 2018, the respective contributors.
* All rights reserved.
*
* Each contributor holds copyright over their respective contributions.
* The project versioning (Git) records all such contribution source information.
*
* Redistribution and use in source and binary forms, with or without
- modification, are permitted provided that the following conditions
- are met:
-
- 1. Redistributions of source code must retain the above copyright
-    notice, this list of conditions and the following disclaimer.
- 2. Redistributions in binary form must reproduce the above copyright
-    notice, this list of conditions and the following disclaimer in the
-    documentation and/or other materials provided with the distribution.
-
- THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
- IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
- OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
- IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
- INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
- NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
- DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
- THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
- (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
- THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef KIS_TABLET_SUPPORT_WIN8_H
#define KIS_TABLET_SUPPORT_WIN8_H

#include <QAbstractNativeEventFilter>

#ifdef _WIN32

#ifdef KRITA
#include <kritaui_export.h>

class KRITAUI_EXPORT KisTabletSupportWin8 : public QAbstractNativeEventFilter
#else
class KisTabletSupportWin8 : public QAbstractNativeEventFilter
#endif
{
  Q_DISABLE_COPY(KisTabletSupportWin8)

public:
  static bool isAvailable();
  static bool isPenDeviceAvailable();

  KisTabletSupportWin8()  = default;
  ~KisTabletSupportWin8() = default;

  bool init();
  // void registerPointerDeviceNotifications();
  virtual bool nativeEventFilter(const QByteArray &eventType, void *message,
                                 long *result) override;
};

#endif  // _WIN32

#endif  // KIS_TABLET_SUPPORT_WIN8_H
