template <typename V>
class MapNode {
	public:
	char* key;
	V value;
	MapNode* next;

	MapNode(char const * key, V value) {
		this->key = new char[strlen(key) + 1];
		strcpy(this->key, key);
		this->value = value;
		next = NULL;
	}

	~MapNode() {
		if (next) {
			delete next;
		}
	}
};

template <typename V>
class hashmap {
	MapNode<V>** buckets;
	int bucketSize;
	int size;

	void rehash() {
		bucketSize *= 2;
		size = 0;
		MapNode<V>** temp = buckets;
		buckets = new  MapNode<V>*[bucketSize];
		for (int i = 0; i < bucketSize; i++) {
			buckets[i] = NULL;
		}
		for (int i = 0; i < bucketSize/2; i++) {
			MapNode<V>* head = temp[i];
			while (head != NULL) {
				insert(head->key, head->value);
				head = head->next;
			}
			head = temp[i];
			delete head;
		}
		delete [] temp;
	}

	int getBucketIndex(char const * key) {
		int sum = 0;
		for(int i = 0; key[i] != '\0'; i++) {
			sum = sum + key[i];
		}
		return sum % bucketSize;
	}

	public:
	hashmap() {
		size = 0;
		bucketSize = 7;
		buckets = new MapNode<V>*[bucketSize];
		for (int i = 0; i < bucketSize; i++) {
			buckets[i] = NULL;
		}
	}

	void insert(char const * key, V value) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* currentHead = buckets[bucketIndex];
		while (currentHead != NULL) {
			if (strcmp(currentHead->key,key) == 0) {
				currentHead->value = value;
				return;
			}
		}	
		size++;
		currentHead = buckets[bucketIndex];
		MapNode<V>* newNode = new MapNode<V>(key, value);
		newNode->next = currentHead;
		buckets[bucketIndex] = newNode;
		if ((size*1.0)/bucketSize > 0.75) {
			rehash();
		}
	}

	void deleteKey(char const * key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* currentHead = buckets[bucketIndex];
		MapNode<V>* prev = NULL;
		while (currentHead != NULL) {
			if (strcmp(currentHead->key,key) == 0) {
				break;
			}
			prev = currentHead;
			currentHead = currentHead->next;
		}
		if (currentHead == NULL) {
			return;
		}
		size--;
		if (prev == NULL) {
			buckets[bucketIndex] = currentHead->next;
		} else {
			prev->next = prev->next->next;
		}
		currentHead->next = NULL;
		delete currentHead;
	}

	bool containsKey(char const * key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* currentHead = buckets[bucketIndex];
		while (currentHead != NULL) {
			if (strcmp(currentHead->key,key) == 0) {
				return true;
			}
			currentHead = currentHead->next;
		}
		return false;
	}

	V find(char const * key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* currentHead = buckets[bucketIndex];
		while (currentHead != NULL) {
			if (strcmp(currentHead->key,key) == 0) {
				return currentHead->value;
			}
			currentHead = currentHead->next;
		}
		throw "Key not found";
	}





};
