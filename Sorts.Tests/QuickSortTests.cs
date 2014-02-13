using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Sorts.Tests
{
    [TestClass]
    public class QuickSortTests
    {
        [TestMethod]
        public void IsSortedTest()
        {
            Random rnd = new Random();

            const int n = 1000;
            int[] array = new List<int>(Enumerable.Range(1, n).Select(v => rnd.Next())).ToArray();

            QuickSort<int> sort = new QuickSort<int>();

            array = sort.Sort(array);

            Assert.IsTrue(TestHelpers<int>.IsSorted(array));
        }
    }
}
