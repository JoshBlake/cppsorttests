using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sorts
{
    public abstract class AbstractSort<T> where T : IComparable<T>
    {
        public abstract T[] Sort(T[] array);

        protected void Swap(T[] array, int i, int j)
        {
            T tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }

        protected bool LessThan(T[] array, int i, int j)
        {
            return array[i].CompareTo(array[j]) < 0;
        }

        protected bool LessThan(T[] array, int i, T v)
        {
            return array[i].CompareTo(v) < 0;
        }

        protected bool LessThan(T[] array, T v, int j)
        {
            return v.CompareTo(array[j]) < 0;
        }
    }
}
