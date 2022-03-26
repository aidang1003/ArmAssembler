#include "Phase1.h"
#include "ArrayList.h"
#include "rotate.h"


// libraries added for testing
#include <stdio.h>
#include <stdlib.h>


bool isPowerOfTwo(uint32_t x) {
  return (x && !(x & (x - 1)));
}

uint32_t toBinary(uint32_t x) {
  //convert a decimal to binary
  // max of uint32_t is 0xFFFFFFFF
  // min of uint32_t is 0x00000000
  uint32_t output = 0b00000000;

  return output;
}

bool evenRotation(uint32_t x) {
  // returns true if a number can be represented using an even number of rotations
  // returns true if the rotations to do this is under 30
  return true;
}

bool fits8Bit(uint32_t x) {
  // returns true if the 1's in a binary number can be represented in 8 bits or less
  // takes in a binary
  
  return true;
}

uint32_t rol(uint32_t n, int i) {
  return n << i;
}

uint32_t rotate(uint32_t num, int rot) {
  //rotates a number by a factor of 2
  int size = sizeof(int) * 8;
  int lsb;
  rot %= size;
  while (rot--) {
    lsb = num & 1;
    num = (num >> 2) & (~(2<<size));
    num = num | (lsb<<size);
  }
  return num;
}

bool validNum(uint32_t val) {
  uint32_t testVal;
  for (int i = 0; i < 15; i++) {
    printf("val Before >> %d\n", val);
    val = rotate(val, i);
    testVal = val & 0xFFFFFF00;
    
    printf("val After >> %d\n", val);
    printf("testVal >> %d\n", testVal);
    
    if (testVal == 0x00000000) {
      return true;
    }
  }
  return false;
}


void check_errors(struct ArrayList *unchecked, struct ArrayList *checked) {
  //printf("in check errors fun \n");
  /*
  int cap;
  cap = unchecked->capacity;
  printf("cap >> %d \n", cap);
  */

  
  //printf("size of checked >> %d \n", size(checked));
  //printf("size of unchecked >> %d \n", size(unchecked));
  
 
  //struct Instruction *UnChInstr;

  struct Instruction Instr;
  struct Instruction tempInst;
  
  for (int i = 0; i < size(unchecked); i++) {
    Instr = get(unchecked, i);
    uint32_t imm = Instr.immediate;
    if (!validNum(imm)) {
      printf("immediate >> %d\n", Instr.immediate);
      
      //tempInst = INVALID();
      tempInst = newInstruction(invalid, AL, 0, 0, 0, 0, 0, 0, "", "");
      Instr = tempInst;
      
    }
    addLast(checked, Instr);
  }


  //enum ID myInstruct = input->instruction_id;
  //enum COND myCond = input->cond;
  //uint8_t myRd = input->rd;
  //uint8_t myRn = input->rn;
  //uint8_t myRm = input->rm;
  //uint8_t myRs = input->rs;
  //int32_t myImm = input->immediate;
  //uint8_t myShift = input->shift_amount;
  //char myLabel[MAX_LABEL_LENGTH] = input->label;
  
  //printf("myRd >> %d \n", myRd);
  //printf("Immediate >> %d \n", myImm);
  
  //printf("size >> %d \n", size(unchecked));
  
  //toString(input, result);
  //printf("%s \n", result);
}
