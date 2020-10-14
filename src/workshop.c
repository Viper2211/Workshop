#include "common.h"

enum {
  STORAGE,
  SHIPMENT,
  INVERTOR,
  AND,
};

void pickUp(uint8_t currentArea,struct bit bit){
  switch (currentArea){
    case STORAGE:
      pickUpStorage(bit);
      break;
    case SHIPMENT:
      pickUpShipment(bit);
      break;
    case INVERTOR:
      pickUpInvertor(bit);
      break;
    case AND:
      pickUpAnd(bit);
      break;
    default:
      break;
  }
}

void addTo(uint8_t currentArea,struct bit bit){
  switch (currentArea){
    case STORAGE:
      addToStorage(bit);
      break;
    case SHIPMENT:
      addToShipment(bit);
      break;
    case INVERTOR:
      addToInvertor(bit);
      break;
    case AND:
      addToAnd(bit);
      break;
    default:
      break;
  }
}

void special(uint8_t currentArea){
  switch (currentArea){
    case SHIPMENT:
      ship();
      break;
    case INVERTOR:
      invert();
      break;
    case AND:
      and();
      break;
    default:
      break;
  }
}

int main(int argc, char *argv[]) {
  char* filename;

  if (argc >= 1){
    filename = argv[1];
  } else {
    printf("Usage : workshop <filename>\n");
    exit(1);
  }

  FILE* source = fopen(filename,"r");
  Storage.storage = malloc(MAX_SIZE*sizeof(struct bit));
  uint8_t currentArea = STORAGE;
  currentBit.value = 1;

  char currentInstruction = fgetc(source);

  while(currentInstruction != EOF) { 
    switch (currentInstruction){
      case 'V':
        special(currentArea);
        break;
      case '^':
        pickUp(currentArea,currentBit);
        break;
      case 'v':
        addTo(currentArea,currentBit);
        break;
      case '>':
        currentArea += (currentArea < AND)? 1 : 0;
        break;
      case '<':
        currentArea -= (currentArea > STORAGE)? 1 : 0;
        break;
      default:
        break;
    }
    currentInstruction = fgetc(source);
  }
  fclose(source);
  free(Storage.storage);
  return 0;
}
