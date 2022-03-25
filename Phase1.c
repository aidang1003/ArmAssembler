#include "Phase1.h"
#include "ArrayList.h"

// libraries added for testing
#include <stdio.h>


void check_errors(struct ArrayList *unchecked, struct ArrayList *checked) {
  //printf("in check errors fun \n");
  /*
  int cap;
  cap = unchecked->capacity;
  printf("cap >> %d \n", cap);
  */
  checked = unchecked;
  
  printf("size >> %d \n", size(checked));
  printf("size >> %d \n", size(unchecked));
  
  /*
  struct Instruction *UnChInstr;
  struct Instruction *chInstr;
  
  for (int i = 0; i < 5 ; i++) {
    *UnChInstr = unchecked->elements[i];
    int32_t imm = UnChInstr->immediate;
    if (imm == 0) {
      *chInstr = unchecked->elements[i];
      printf("entered if loop\n");
    }
    // printf("Immediate %d >> %d \n", i, imm);
  }
  */
  
  //struct Instruction *input = unchecked->elements;
  //struct Instruction *inputcheck = checked->elements;
  
  //enum ID myInstruct = input->instruction_id;
  //enum COND myCond = input->cond;
  //uint8_t myRd = input->rd;
  //uint8_t myRn = input->rn;
  //uint8_t myRm = input->rm;
  //uint8_t myRs = input->rs;
  //int32_t myImm = input->immediate;
  //uint8_t myShift = input->rd;
  //char myLabel[MAX_LABEL_LENGTH] = input->label;
  
  //printf("myRd >> %d \n", myRd);
  //printf("Immediate >> %d \n", myImm);
  
  //printf("size >> %d \n", size(unchecked));
  
  //toString(input, result);
  //printf("%s \n", result);
}
