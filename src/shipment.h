
struct {
  struct bit cargo[MAX_SIZE];
  int currentSize;
} Shipment;
void addToShipment(struct bit bit){
  Shipment.cargo[Shipment.currentSize] = bit;
  Shipment.currentSize++;
}
void ship(){
  for (int i=0;i<Shipment.currentSize;i++){
    printf("%d",Shipment.cargo[i].value);
  }
  printf("\n");
}
void pickUpShipment(struct bit bit){
  bit = Shipment.cargo[Shipment.currentSize-1];
}