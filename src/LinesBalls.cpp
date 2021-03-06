/*
  Copyright (C) 2015 Jolla Ltd.
  Contact: Slava Monich <slava.monich@jolla.com>

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS
  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "LinesBalls.h"

LinesBalls::LinesBalls()
{
}

void LinesBalls::addPoint(LinesPoint aPoint, LinesColor aColor)
{
    iPoints.append(aPoint);
    iPointToColor.insert(aPoint, aColor);
}

void LinesBalls::addPoints(LinesPoints aPoints, LinesColor aColor)
{
    const int n = aPoints.size();
    for (int i=0; i<n; i++) addPoint(aPoints.value(i), aColor);
}

bool LinesBalls::removePoint(LinesPoint aPoint)
{
    if (iPointToColor.remove(aPoint)) {
        iPoints.removeAll(aPoint);
        return true;
    }
    return false;
}

void LinesBalls::removePointAtIndex(int aIndex)
{
    LinesPoint p = iPoints.value(aIndex);
    QVERIFY(iPointToColor.remove(p));
    iPoints.removeAll(p);
}
