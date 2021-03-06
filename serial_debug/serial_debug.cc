// Copyright 2010 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "avrlib/boot.h"
#include "avrlib/serial.h"
#include "avrlib/output_stream.h"

using namespace avrlib;

typedef Serial<SerialPort0, 9600, DISABLED, POLLED> DebugPort;
Serial<SerialPort1, 31250, BUFFERED, DISABLED> midi;

int main(void) {
  OutputStream<DebugPort> debug_output;

  Boot(false);
  DebugPort::Init();
  midi.Init();
  while (1) {
    if (midi.readable()) {
      debug_output << int(midi.ImmediateRead()) << endl;
    }
  }
}
