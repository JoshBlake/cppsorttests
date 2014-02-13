using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sorts
{

    // loop over array, finding the smallest value, move it into position, rinse, repeat
    // BigO = n ^ 2
    public class SelectionSort<T> : AbstractSort<T> where T : IComparable<T>
    {
        public override T[] Sort(T[] array)
        {
            int length = array.Length;
            for (int i = 0; i < length; i++)
            {
                int min = i;
                for (int j = i; j < length; j++)
                    if (LessThan(array, j, min))
                        min = j;

                array[i] = array[min];
            }

            return array;
        }
    }
}
