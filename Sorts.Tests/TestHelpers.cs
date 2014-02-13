using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sorts.Tests
{
    public static class TestHelpers<T> where T : IComparable<T>
    {
        public static bool IsSorted(T[] array)
        {
            for (int i = 1; i < array.Length; i++)
            {
                if (array[i - 1].CompareTo(array[i]) > 1)
                    return false;
            }

            return true;

        }
    }
}
