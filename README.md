# Monty Interpreter

Bienvenido al Intérprete de Bytecode de Monty. Este intérprete se creó en lenguaje C y cumple con ISO90, ISO99y ISO11. Lee archivos de código de bytes Monty de cualquier extensión (preferiblemente .maunque no importa) e interpreta los códigos de operación contenidos.

Nuestro intérprete se puede ejecutar como una pila (LIFO) o una cola (FIFO). El modo se puede cambiar a mitad del guión. El intérprete puede manejar una variedad de códigos de operación de Monty, incluida la impresión, operaciones matemáticas y más; todos los códigos de operación manejados se enumeran a continuación.
## Installation


- Clone this repository: `git clone "https://github.com/paolo-abarca/monty.git"`

- Change directories into the repository: `cd monty`

- Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

- Run the shell in interactive mode: `./monty file.m`


## Monty Opcodes

* **push**
    * Prints the top value of the stack/queue.
    * Pushes an element to the stack.
    * The parameter <int> must be an integer.
* **pall**
    * Prints all values in the stack/queue, starting from the top.
* **pin**
    * Prints the top value of the stack/queue.
* **pop**
    * Removes the top element of the stack/queue.
* **swap**
    * Swaps the top two elements of the stack/queue.
* **nop**
    * Does not do anything.
* **add**
    * Adds the top two elements of the stack/queue.
    * The result is stored in the second element from the top and the top element is popped.
* **sub**
    * Subtracts the top element of the stack/queue from the second element from the top.
    * The result is stored in the second element from the top and the top element is removed.
* **mul**
    * Multiplies the top two elements of the stack/queue.
    * The result is stored in the second element from the top and the top element is removed.
* **div**
    * Divides the second element from the top of the stack/queue by the top element.
    * The result is stored in the second element from the top and the top element is removed.
* **mod**
    * Computes the modulus of the second element from the top of the stack/queue divided by the top element.
    * The result is stored in the second element from the top and the top element is removed.
* **pchar**
    * Prints the character value of the top element of the stack/queue.
    * The integer at the top is treated as an ASCII value.
* **pstr**
    * Prints the string contained in the stack/queue.
* **rotl**
    * Rotates the top element of the stack/queue to the bottom.
* **rotr**
    * Rotates the bottom element of the stack/queue to the top.
* **stack**
    * Switches a queue to stack mode.
* **queue**
    * Switches a stack to queue mode.






## Authors


- Juan Salinas | [GitHub](https://github.com/JSM788)  
- Paolo Abarca | [GitHub](https://github.com/paolo-abarca)
