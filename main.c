#include <stdint.h>
#include <stdio.h>


//Display map
//64 * 32 pixels
//I'll use this to display the sprites?
//The sprites are 8bit numbers? So there's some kind of mapping here.
//I might actually have to make this just a bitmap and then map the bytes of the sprite to the
//pixels in this display_map;
//if a pixel is on I'll change it's value to 1
//if it's off I'll change the value to 0
unsigned short display_map[32][64];

/*
So a function to push values onto my stack
args.
  reference to the stack itself
  stack counter to track position
  the data we're adding to the stack (at most a 16 bit number...am I missing something?)
*/

uint16_t stack[10];
int top = -1;
int stack_error = 0; // 0 = no error, 1 = overflow, 2 = underflow

// STACK METHODS //
// Push to stack to push to our stack, I set the stack size to 10
// These methods will set a global variable based on the result of the operation


void push_to_stack(int* top, uint16_t* stack, uint16_t value){
  if(*top + 1 < 10){
    (*top)++; //dereference top and increment
    stack[*top] = value;
    stack_error = 0;
  } else {
    fprintf(stderr, "stack overflow\n");
    fflush(stderr);
    stack_error = 1;
  }
}

uint16_t pop_from_stack(int* top, uint16_t* stack){
  if(*top == -1){
    fprintf(stderr, "stack underflow\n");
    fflush(stderr);
    stack_error = 2;
    return 0;
  }
  uint16_t value = stack[*top];
  (*top)--;
  stack_error = 0;
  return value;
}

int main(void){
  //TODO A heckin lot bro

  return 0;
}