using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lottery
{
    internal class Lot : IEquatable<Lot>
    {
        public string fullname { get; set; }

        public int ID { get; set; }

        public override string ToString()
        {
            return "ID: " + ID + "   Name: " + fullname;
        }
        public override bool Equals(object obj)
        {
            if (obj == null) return false;
            Lot objAsLot = obj as Lot;
            if (objAsLot == null) return false;
            else return Equals(objAsLot);
        }
        public override int GetHashCode()
        {
            return ID;
        }
        public bool Equals(Lot other)
        {
            if (other == null) return false;
            return (this.ID.Equals(other.ID));
        }
        // Should also override == and != operators.
    }
}
