using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sorts
{
    public class QuickSort<T> : AbstractSort<T> where T : IComparable<T>
    {
        public override T[] Sort(T[] array)
        {
            Sort(array, 0, array.Length - 1);
            return array;
        }

        private void Sort(T[] array, int lo, int hi)
        {
            if (lo >= hi) return;

            int split = Partition(array, lo, hi);

            Sort(array, lo, split - 1);
            Sort(array, split + 1, hi);
        }

        private int Partition(T[] array, int lo, int hi)
        {
            T v = array[lo];
            int i = lo;
            int j = hi + 1;

            while (true)
            {
                while (LessThan(array, ++i, v))
                    if (i == hi) break;
                while (LessThan(array, v, --j))
                    if (j == lo) break;

                if (i >= j)
                    break;

                Swap(array, i, j);
            }

            Swap(array, lo, j);

            return j;
        }


    }
}
