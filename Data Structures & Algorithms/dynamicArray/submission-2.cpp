class DynamicArray {
 public:
  DynamicArray(int capacity) : mCap(capacity), mLen(0) { mData = new int[mCap]; }

  int get(int i) {
    return mData[i];
  }

  void set(int i, int n) {
    mData[i] = n;
  }

  void pushback(int n) {
    if (mLen == mCap) {
      resize();
    }
    mData[mLen] = n;
    mLen++;
  }

  int popback() {
    if (mLen > 0){
        mLen--;
    }
    return mData[mLen];
  }

  void resize() {
    int* temp = new int[mCap * 2];
    for (int i = 0; i < mLen; i++) {
      temp[i] = mData[i];
    }
    delete[] mData;

    mData = temp;
    mCap *= 2;
  }

  int getSize() { return mLen; }

  int getCapacity() { return mCap; }

 private:
  int* mData;
  int mCap;
  int mLen;
};
