struct {
  uint8_t* storage;
  unsigned top;
} Storage;

void addToStorage(struct bit bit){
  Storage.storage[Storage.top] = bit.value;
  Storage.top++;
}
void pickUpStorage(struct bit bit){
  bit.value = (Storage.top-1>=0) ? Storage.storage[Storage.top-1] : 0;
}