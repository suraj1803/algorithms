package com.suraj.algorithms.datastructures;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;

/**
 * Dynamic Array implementation.
 * A dynamic array automatically grows in size when it becomes full.
 *
 * @param <T> the type of elements stored in the array
 *
 * @author Suraj Biswas
 */
public class DynamicArray<T> implements Iterable<T> {

    private Object[] arr;
    private int size;
    private int capacity;

    /**
     * Constructs a DynamicArray with default capacity 16.
     */
    public DynamicArray() {
        this(16);
    }

    /**
     * Constructs a DynamicArray with the specified initial capacity.
     *
     * @param initialCapacity the initial capacity of the array
     * @throws IllegalArgumentException if the initial capacity is negative
     */
    public DynamicArray(int initialCapacity) {
        if (initialCapacity < 0)
            throw new IllegalArgumentException("Illegal Capacity: " + initialCapacity);

        this.capacity = initialCapacity;
        arr = new Object[capacity];
    }

    /**
     * Returns the number of elements currently stored in the array.
     *
     * @return the number of elements in the array
     */
    public int size() {
        return size;
    }

    /**
     * Checks whether the array is empty.
     *
     * @return true if the array contains no elements, false otherwise
     */
    public boolean isEmpty() {
        return size() == 0;
    }

    /**
     * Checks whether the array is full.
     *
     * @return true if the array is full, false otherwise
     */
    public boolean isFull() {
        return size() == capacity;
    }

    /**
     * Validates the specified index.
     *
     * @param index the index to validate
     * @throws IndexOutOfBoundsException if the index is out of range
     */
    private void checkIndex(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException(index);
        }
    }

    /**
     * Returns the element at the specified index.
     *
     * @param index the index of the element
     * @return the element at the specified index
     * @throws IndexOutOfBoundsException if the index is out of range
     */
    @SuppressWarnings("unchecked")
    private T getElement(int index) {
        checkIndex(index);
        return (T) arr[index];
    }

    /**
     * Returns the element at the specified index.
     *
     * @param index the index of the element
     * @return the element at the specified index
     * @throws IndexOutOfBoundsException if the index is out of range
     */
    public T get(int index) {
        return getElement(index);
    }

    /**
     * Replaces the element at the specified index with the given item.
     *
     * @param index the index of the element to replace
     * @param item the new element
     * @throws IndexOutOfBoundsException if the index is out of range
     */
    public void set(int index, T item) {
        checkIndex(index);
        arr[index] = item;
    }

    /**
     * Adds an element to the end of the array.
     * The array capacity is doubled if the array becomes full.
     *
     * @param item the element to add
     */
    public void add(T item) {

        if (isFull()) {

            capacity = capacity * 2;

            Object[] newArr = new Object[capacity];

            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }

            arr = newArr;
        }

        arr[size++] = item;
    }

    /**
     * Removes and returns the element at the specified index.
     * All elements after the removed element are shifted left by one position.
     *
     * @param index the index of the element to remove
     * @return the removed element
     * @throws IndexOutOfBoundsException if the index is out of range
     */
    public T removeAt(int index) {

        checkIndex(index);

        T item = getElement(index);

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        arr[--size] = null;

        return item;
    }

    /**
     * Removes the first occurrence of the specified item from the array.
     *
     * @param item the item to remove
     * @return true if the item was removed successfully, false otherwise
     */
    public boolean remove(T item) {

        for (int i = 0; i < size; i++) {

            if (Objects.equals(getElement(i), item)) {
                removeAt(i);
                return true;
            }
        }

        return false;
    }

    /**
     * Returns the index of the first occurrence of the specified item.
     *
     * @param item the item to search for
     * @return the index of the item, or -1 if the item is not found
     */
    public int indexOf(T item) {

        for (int i = 0; i < size; i++) {

            if (Objects.equals(getElement(i), item)) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Checks whether the array contains the specified item.
     *
     * @param item the item to search for
     * @return true if the item exists in the array, false otherwise
     */
    public boolean contains(T item) {

        for (int i = 0; i < size; i++) {

            if (Objects.equals(getElement(i), item)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Returns an iterator over the elements in the array.
     *
     * @return an iterator for traversing the array
     */
    @Override
    public Iterator<T> iterator() {

        return new Iterator<T>() {

            private int index = 0;

            /**
             * Checks whether more elements are available.
             *
             * @return true if more elements exist, false otherwise
             */
            @Override
            public boolean hasNext() {
                return index < size;
            }

            /**
             * Returns the next element in the iteration.
             *
             * @return the next element
             * @throws NoSuchElementException if no more elements exist
             */
            @Override
            public T next() {

                if (!hasNext()) {
                    throw new NoSuchElementException();
                }

                return getElement(index++);
            }
        };
    }
}