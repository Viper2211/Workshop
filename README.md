# Workshop
A esoteric programming language based off of the `Factory` programming language.

A workshop program provides instructions for a virtual claw that moves around and interacts with different sections of the workshop. The language itself is operates in bits. 

Here is a description of the `Factory` language taken from its entry on [Esolangs](esolangs.org):
> In this language you control a claw in the byte factory, moving `1`'s and `0`'s around. Here is a map of the factory on program start:

Not only that, but workshop is turing complete ~~so does anyone want to write a web app in it with me?~~.

That just about summarizes all that workshop does. Here is a map of the "workshop" when the program begins:
```
     ||
     ||
    /  \
    \  /



 _____________ |   [:=:]  | !!!!!!!! | &&& 
    storage    | shipping | Invertor | and
```
> This was also partially based off of the [entry](https://esolangs.org/wiki/Factory) for factory

# A Snippet on the Code
Most of the code is self explanatory and I tried my best to be as memory efficient as possible. I still have a few more ideas about how to make the interpreter faster and more efficient, but I'll probably do it later.

# Using Workshop
Workshop code is written in a file that ends with `.ws`.
The claw always carrys one bit (because it has an inbuilt production system). In the beginning of the program, it's current bit is set to `1`.

## Commands
### `<`
This command moves the claw left. If it is already above `storage`, the claw does not move.
### `>` 
This command moves the claw right. If the claw is already above the `and` area, it does not move.
### `^`
This command picks up the current bit in the current area.
### `v` 
This command drops the current bit in the current area.
### `V`
This command actives the _special_ ability of the current area. The special abilities of each area are listed below.
- Storage - No special ability
- Shipment - _Ships_ the current data to the screen
- Invertor - Its current value is replace by the opposite bit
- And - Takes two bits and replaces its value with `1` if both values are `1`.

And that's about it

### Quick Note about Storage
The storage section is a stack, as in, the first in, the last out. The max size of the storage can be changed by going to `src/common.h` file and changing the `MAX_SIZE` macro to whatever you want the max size of your stack to be.

# Credits
- Workshop Interpreter - @Viper2211(Me)
- Workshop Syntax - @Viper2211 & [Factory](https://esolangs.org/wiki/Factory)
- Workshop Initial Testing - Suprasada J and Aakarshan K
## Written and Tested on [`repl.it`](https://repl.it/@Viper2211/)
