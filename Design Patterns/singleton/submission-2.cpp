class Singleton {
 private:
  static Singleton* uniqueInstance;
  std::string mValue{};

  Singleton() {}

 public:
  static Singleton* getInstance() {
    if (!uniqueInstance) {
      uniqueInstance = new Singleton();
    }
    return uniqueInstance;
  }

  string getValue() { return mValue; }

  void setValue(string& value) { mValue = value; }
};

Singleton* Singleton::uniqueInstance{nullptr};