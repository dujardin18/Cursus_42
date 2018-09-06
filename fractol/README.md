

CONTAINER REGISTERS:

char st_reg; >> STATUS REGISTER

| 7 | 6 | 5 | 4 | 3 | 2 | 1   | 0 |
|   |   |   |   |   |   |IMGSI|MLXI|

- MLXI<0:1> : MLX INIT > MLX has been initialized
- IMGSI<1:1> : IMGS INIT > At least one image has been initialized

char err_reg; >> ERROR REGISTER

| 7 | 6 | 5 | 4 | 3 | 2   | 1     | 0    |
|   |   |   |   |   |PX_OV|IMGSIERR|MLXIER|

- MLXIER<0:1> : MLX INIT Error
- IMGSIERR<1:1> : IMG INIT Error
- PX_OV<2:1> : Pixel overflow

char imgs_used; >> Number of used imgs
| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| - | - | - | - | - | - | - | - |

- IMGS_USED<0:8> : Number of used image by mlx window




| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|   |   |   |   |   |   |   ||
