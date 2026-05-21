/**
 * Dynamic Array implementation
 * @author Suraj Biswas, surajbiswas182003@gmail.com
 */
package com.suraj.algorithms.datastructures;

import java.util.Objects;

public class DynamicArray<T> {
    private Object[] arr;
    private int size;
    private int capacity;

    public DynamicArray() {
        this(16);
    }

    public DynamicArray(int initialCapacity) {
        if (initialCapacity < 0) throw new IllegalArgumentException("Illegal Capacity: " + initialCapacity);
        this.capacity = initialCapacity;
        arr = new Object[capacity];
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public boolean isFull() {
        return size() == capacity;
    }

    private void checkIndex(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException(index);
        }
    }

    @SuppressWarnings("unchecked")
    private T getElement(int index) {
        checkIndex(index);
        return (T) arr[index];
    }

    public T get(int index) {
        return getElement(index);
    }

    public void set(int index, T item) {
        checkIndex(index);
        arr[index] = item;
    }

    public void add(T item) {
        if (isFull()) {
            capacity = capacity*2;
            Object[] newArr = new Object[capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            arr = newArr;
        }
        arr[size++] = item;
    }

    public T removeAt(int index) {
        checkIndex(index);
        T item = getElement(index);
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size--] = null;
        return item;
    }

    public boolean remove(T item) {
        for (int i = 0; i < size; i++) {
            if (Objects.equals(getElement(i),item)) {
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    public int indexOf(T item) {

        for (int i = 0; i < size; i++) {
            if (Objects.equals(getElement(i),item)) {
                return i;
            }
        }
        return -1;
    }

    public boolean contains(T item) {
        for (int i = 0; i < size; i++) {
            if (Objects.equals(getElement(i),item)) {
                return true;
            }
        }
        return false;
    }
}
