
struct {
  struct bit bit;
} Invertor;
void addToInvertor(struct bit bit){
  Invertor.bit = bit;
}
void invert(){
  Invertor.bit.value = (Invertor.bit.value==1)? 0 : 1;
}
void pickUpInvertor(struct bit bit){
  bit = Invertor.bit;
}

struct {
  struct bit bits[2];
  unsigned bitsRecieved:1;
  struct bit value;
} And;
void addToAnd(struct bit bit){
  And.bits[And.bitsRecieved] = bit;
  if (And.bitsRecieved < 2) And.bitsRecieved++;
}
void and(){
  And.value.value = (And.bits[0].value+And.bits[1].value==2)? 1 : 0;
}
void pickUpAnd(struct bit bit){
  bit = And.value;
}