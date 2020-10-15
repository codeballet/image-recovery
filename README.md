# Image Recovery

The Image Recovery program extracts deleted JPG pictures from memory card images.

## How to use

The code is written in C, so first, you need to compile it into an executable file.

Example:
`make recover`

Use the resulting executable file with the path to a card image:

```
recover <card-image>
```

Example:

```
./recover card.raw
```

The jpg images will be stored in the current directory.

## Licence

MIT
