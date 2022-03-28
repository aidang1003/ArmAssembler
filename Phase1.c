#include "Phase1.h"
#include "ArrayList.h"
#include "rotate.h"
#include "InstructionFactory.h"
#include <stdlib.h>


// libraries added for testing
#include <stdio.h>



bool isPowerOfTwo(uint32_t x) {
  return (x && !(x & (x - 1)));
}

uint32_t extractBits(uint32_t number, int k, int p) {
  // misc function that might help
  // returns last k bits from a number
  // k is the number of bits returned
  // p is the position it is returning from
  return (((1 << k) - 1 ) & (number >> (p)));
}

uint32_t absVal(uint32_t x) {
  // takes in a uint32_t number and returns the absolute value
  //printf("absVal >> %x\n", x);
  //printf("absVal after shift >> %x\n", x>>31);
  if (x >> 31 == 1) {
    return (x ^ 0xFFFFFFFF) + 1;
  }
  return x;
}

uint32_t rotate(uint32_t num, int rot) {
  //rotates a number by a factor of 2
  //replaced this function with circular rotate
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

uint32_t circularRot(uint32_t n, int bits) {
  // want to circularly rotate 2 bits to the right
  // function only works with 2 bits on a 32-bit number
  int tempBits[bits];
  uint32_t tempN = n;
  for (int i = 0; i < bits; i++) {
    int tempBit = tempN % 2;
    tempBits[i] = tempBit;
    tempN = ((tempN - tempBit)/ 2) ;
  }
  
  if (tempBits[0] == 1 && tempBits[1] == 1) {
    n = n >> 2;
    return n + (0b11 << 29);
  } else if (tempBits[0] == 1 && tempBits[1] == 0) {
    n = n >> 2;
    return n + (0b10 << 29);
  } else if (tempBits[0] == 0 && tempBits[1] == 1) {
    n = n >> 2;
    return n + (0b01 << 29);
  } else { 
    return n >> 2;
  }
}

bool validNum(uint32_t val) {
  uint32_t testVal;
  for (int i = 0; i < 32; i++) {
    //printf("val Before >> %d\n", val);
    
    val = circularRot(val, 2); // circuarly rotate 2 bits right
    testVal = val & 0xFFFFFF00; // test value for it one of the rotated values has only 8 bits in the last position

    //printf("val After >> %d\n", val);
    //printf("testVal >> %d\n", testVal);
    
    if (testVal == 0x00000000) { // if the testVal is zero it is valid
      //printf("test val is true \n\n");
      return true;
    }
  }
  //printf("test val is false \n\n");
  return false;
}


void check_errors(struct ArrayList *unchecked, struct ArrayList *checked) {
  //printf("in check errors fun \n");
  /*
  int cap;
  cap = unchecked->capacity;
  printf("cap >> %d \n", cap);
  */


  struct Instruction Instr;
  
  for (int i = 0; i < size(unchecked); i++) {
    Instr = get(unchecked, i);
    uint32_t imm = Instr.immediate;

    //printf("Immediate >> %d\n", imm);
    enum ID id = Instr.instruction_id;
    
    //printf("Immediate >> %d\n", imm);
    
    if (imm >> 31 == 1) {
      //printf("entered if \n");
      Instr.immediate = absVal(imm);
      //printf("abs immediate %d\n", Instr.immediate);
      
      switch(id) {
        case 1:
          Instr.instruction_id = 3;
          break;
        case 2:
          Instr.instruction_id = 4;
          break;
        case 3:
          Instr.instruction_id = 1;
          break;
        case 4:
          Instr.instruction_id = 2;
          break;
        case 6:
          //Instr = INVALID();
          break;
        default:
          break;
      }
      
      imm = Instr.immediate;
    }
    //printf("Immediate after >> %d\n", imm);
    
    if (!validNum(imm)) {
    
      printf("immediate >> %x\n", Instr.immediate);   
      printf("imm >> %x\n", imm);   
      Instr = INVALID();
      
    }
    
    //printf("valid num >> %d \n", validNum(imm));
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
  
}
