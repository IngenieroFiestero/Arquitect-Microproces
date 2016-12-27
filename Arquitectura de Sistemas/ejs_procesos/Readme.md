# Ejercicios de Procesos

## Forks

#### fork

```
$ ./fork
Hijo: global 2 local 3 
global 0 local 1
```

#### fork_1

```
$ ./fork_1
Soy el padre
Soy el hijo
```

#### fork_2

```
$ ./fork_2
Comienza la ejecucion
Soy el padre
Termina la ejecucion
Soy el hijo
Termina la ejecucion
```

#### time_fork

```
$ ./time_fork
Tiempo: 6, 18990 
Tiempo: 2, 18991 
Tiempo: 4, 18992 
Tiempo: 2, 18993 
Soy hijo 18991: He dormido 2 segundos
Soy hijo 18993: He dormido 2 segundos
Soy hijo 18992: He dormido 4 segundos
Soy hijo 18990: He dormido 6 segundos
```

#### bucle_fork

```
$ ./bucle_fork 2
Acabo: soy 19309
Acabo: soy 19310
Acabo: soy 19312
Acabo: soy 19311
```
