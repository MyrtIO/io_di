# io_di

Ultra-compact library for Dependency Injection. Allows to simplify singleton management in a small micro-controller project.

## Usage

### Provide

To provide the dependency, you need to create 2 files. In the `.cpp` (or `.cc`) file you create the entity to be provided, and in the `.h` file you represent that entity externally. The export takes place via the interface. Example:

```cpp
// platform.h
#include <io_di.h>
#include "leds/leds.h"
#include "interfaces.h"

IO_PROVIDE(ILightPlatform, LightPlatform);
```

```cpp
// platform.cpp
#include "platform.h"

IO_PROVIDE_INSTANCE(ILightPlatform, LightPlatform);
```

### Inject

The `IO_INJECT` macro is used for injection. It returns a pointer to an instance of the class which implements the interface.

```cpp
// clock.h
#include <io_di.h>
#include "leds/leds.h"

class ClockCapability {
private:
  ILightPlatform* leds_ = IO_INJECT(ILightPlatform);
}
```
