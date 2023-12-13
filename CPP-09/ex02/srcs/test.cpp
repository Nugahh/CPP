template <typename T> void mergeSort(T &container, int left, int right) {
        if (left >= right)
            return; // Base case for recursion

    // we use the middle index to split the container in two halves
        int mid = left + (right - left) / 2;
        mergeSort(container, left, mid);
        mergeSort(container, mid + 1, right);

        // Temporary container to store the merged result
        T temp;
        int i = left, j = mid + 1;

        // Merge the two halves into temp
        while (i <= mid && j <= right) {
            if (container[i].first <= container[j].first)
                temp.push_back(container[i++]);
            else
                temp.push_back(container[j++]);
        }
        // Copy remaining elements
        while (i <= mid)
            temp.push_back(container[i++]);
        while (j <= right)
            temp.push_back(container[j++]);

        // Copy back the merged elements to the original container
        for (int k = left; k <= right; k++)
            container[k] = temp[k - left];
    }