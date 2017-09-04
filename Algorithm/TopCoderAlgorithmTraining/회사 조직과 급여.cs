using System;
using System.Collections.Generic;

namespace Studying_CS
{
    class CorporationSalary
    {
        private long[] salar;

        public long totalSalary(string[] relations)
        {
            salar = new long[relations.Length];

            long sum = 0;

            for(int i = 0; i < relations.Length; i++)
            {
                Salary(i, relations);
            }

            return sum;
        }

        private long Salary(int now, string[] relations)
        {
            if (salar[now] == 0)
            {
                long salary = 0;
                string relation = relations[now];

                for (int i = 0; i < relations.Length; i++)
                {
                    if (relation[now] == 'Y')
                    {
                        salary += Salary(i, relations);
                    }
                }

                salar[now] = salary;
            }

            return salar[now];
        }
    }
}
