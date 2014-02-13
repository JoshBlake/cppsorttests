using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sorts
{
    // Big O(n^2)
    public class InsertionSort<T> : AbstractSort<T> where T : IComparable<T>
    {
        public override T[] Sort(T[] array)
        {
            int n = array.Length;
            for (int i = 1; i < n; i++)
            {
                for (int j = i; j > 0 && LessThan(array, j, j-1); j--)
                {
                    Swap(array, j, j-1);
                }
            }
            return array;
        }
    }
}
