# Image Recovery

The Image Recovery program extracts deleted JPG pictures from memory card images.

The program is written in C, as an assignment for the CS50 course at Harvard.

## Compiling

In order to compile the code, you need to have 'make' and 'clang' installed.

To compile the code into an executable file:

```
make recover
```

## How to use

Use the resulting executable file with the path to a card image:

```
recover card-image
```

Example:

```
./recover card.raw
```

The jpg images will be stored in the current directory.

## Licence

MIT
