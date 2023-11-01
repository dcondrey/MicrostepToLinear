# MicrostepToLinear Arduino Library

## Overview

Convert stepper motor microsteps to linear distance with ease and precision. Available in the Arduino Library Manager.

## Features

- Customizable step angle, microsteps, and pitch
- Efficient conversion from microsteps to linear distance

## Installation

### Arduino Library Manager

1. Open Arduino IDE, go to `Sketch` > `Include Library` > `Manage Libraries...`.
2. In the Library Manager window, enter "MicrostepToLinear" into the search box.
3. Click the "Install" button when you see the library.

### Arduino CLI

1. Install the library directly using Arduino CLI.

```bash
arduino-cli lib install MicrostepToLinear
```

### Manual Installation

```bash
git clone https://github.com/dcondrey/MicrostepToLinear.git
cd MicrostepToLinear
arduino-cli lib install .
```

## Usage

Include the library and initialize the converter object.

```arduino
#include "MicrostepToLinear.h"
MicrostepToLinear converter(1.8, 16, 2.0);
```

Convert microsteps to linear distance:

```arduino
float distance = converter.convert(3200);
```

## License

MIT