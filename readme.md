# MicrostepToLinear Arduino Library

## Overview

Convert stepper motor microsteps to linear distance with ease and precision.

- Customizable step angle, microsteps, and pitch
- Efficient and easy-to-use API
- Example sketch included

## Installation

### Arduino CLI

```bash
arduino-cli lib install MicrostepToLinear
```

### Arduino IDE

Download the ZIP and import via `Sketch` > `Include Library` > `Add .ZIP Library`.

## Usage

Include the library and initialize:

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