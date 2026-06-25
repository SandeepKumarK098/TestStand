using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DotNetEnums
{
	public class Class1
	{
		[Flags]
		public enum Color3Bit : byte
		{
			Black = 0,
			Red = 1,
			Green = 2,
			Blue = 4,
			White = Red | Green | Blue
		}

		[Flags]
		public enum ColorCMY3Bit : byte
		{
			Black = 0,
			Magenta = 1,
			Yellow = 2,
			Cyan = 4,
			White = Magenta | Yellow | Cyan
		}

		[Flags]
		public enum Color3BitWithEmbellishments : byte
		{
			Black = 0,
			Noir = Black,
			Red = 1,
			Scarlet = Red,
			Green = 2,
			Blue = 4,
			White = Red | Green | Blue
		}

		[Flags]
		public enum Color24Bit : UInt32
		{
			Black = 0,
			Red = 0xff,
			Green = 0xff00,
			Blue = 0xff0000,
			White = Red | Green | Blue
		}

		public enum CompassDirection
		{
			North = 0,
			NorthEast = 45,
			East = 90,
			SouthEast = 135,
			South = 180,
			SouthWest = 225,
			West = 270,
			NorthWest = 315,
			N = North,
			S = South,
			E = East,
			W = West,
			NE = NorthEast,
			SE = SouthEast,
			NW = NorthWest,
			SW = SouthWest
		}

		public enum Service
		{
			Army,
			Navy,
			AirForce,
			Marines,
			CoastGuard
		}

		[Flags]
		public enum Bits16 : UInt16
		{
			Bit0 = 1,
			Bit1 = 1 << 1,
			Bit2 = 1 << 2,
			Bit3 = 1 << 3,
			Bit4 = 1 << 4,
			Bit5 = 1 << 5,
			Bit6 = 1 << 6,
			Bit7 = 1 << 7,
			Bit8 = 1 << 8,
			Bit9 = 1 << 9,
			Bit11 = 1 << 10,
			Bit12 = 1 << 11,
			Bit13 = 1 << 12,
			Bit14 = 1 << 13,
			Bit15 = 1 << 14,
			Bit16 = 1 << 15
		}

		public enum Options : UInt64
		{
			Option0 = 1,
			Option37 = 1ul << 37,
			Option63 = 1ul << 63
		}

		public enum PowersOf10 : Int64
		{
			Ten0 = 1,
			Ten1 = 10,
			Ten2 = 100,
			Ten3 = 1000,
			Ten4 = 10000,
			Ten5 = 100000,
			Ten6 = 1000000,
			Ten7 = 10000000,
			Ten8 = 100000000,
			Ten9 = 1000000000,
			Ten10 = 10000000000,
			Ten11 = 100000000000,
			Ten12 = 1000000000000,
			Ten13 = 10000000000000,
			Ten14 = 100000000000000,
			Ten15 = 1000000000000000,
			Ten16 = 10000000000000000,
			Ten17 = 100000000000000000,
			Ten18 = 1000000000000000000
		}


		public enum BigSignedEnum : Int64
		{
			Max = Int64.MaxValue,
			Min = Int64.MinValue
		}

		public static String ColorString(Color3Bit color)
		{
			switch (color)
			{
				case Color3Bit.Black:
				case Color3Bit.Red:
				case Color3Bit.Blue:
				case Color3Bit.Green:
				case Color3Bit.White:
					string retVal = Enum.Format(typeof(Color3Bit), color, "g");
					return retVal;

				default: break;
			}

			if (color == (Color3Bit.Red | Color3Bit.Green)) { return "Yellow"; }
			if (color == (Color3Bit.Red | Color3Bit.Blue)) { return "Magenta"; }
			if (color == (Color3Bit.Green | Color3Bit.Blue)) { return "Cyan"; }

			throw new ArgumentOutOfRangeException("Unknown color " + (Byte)color + ".");
		}

		public static Color24Bit UpConvert(Color3Bit color)
		{
			Color24Bit color24 = ((color & Color3Bit.Red) == 0) ? 0 : Color24Bit.Red;
			color24 |= ((color & Color3Bit.Blue) == 0) ? 0 : Color24Bit.Blue;
			color24 |= ((color & Color3Bit.Green) == 0) ? 0 : Color24Bit.Green;

			return color24;
		}

		public static Int64 SumPowersOf10(PowersOf10[] powToSum)
		{
			Int64 sum = 0;

			foreach (var num in powToSum)
			{
				sum += (Int64)num;
			}

			return sum;
		}

		public static CompassDirection[] MakeCardinalDirections()
		{
			CompassDirection[] cardinal = new CompassDirection[4];

			int ii = 0;
			cardinal[ii] = CompassDirection.N; ++ii;
			cardinal[ii] = CompassDirection.S; ++ii;
			cardinal[ii] = CompassDirection.E; ++ii;
			cardinal[ii] = CompassDirection.W; ++ii;

			return cardinal;
		}

		public static void GetColors(String color, ref Color3Bit color3, out Color24Bit color24)
		{
			color24 = (Color24Bit)Enum.Parse(typeof(Color24Bit), color);
			color3 = (Color3Bit)Enum.Parse(typeof(Color3Bit), color);
		}

		public static void TakesColorCMY3Bit(ColorCMY3Bit color) { }

		public static Service ReturnInvalidServce()
		{
			return (Service)27;
		}

		public static Color3Bit CombineColors(Color3Bit[] mixture)
		{
			Color3Bit combo = Color3Bit.Black;

			foreach(var color in mixture)
			{
				combo |= color;
			}

			return combo;
		}
		public static Color3Bit CombineColors2D(Color3Bit[][] mixture)
		{
			Color3Bit combo = Color3Bit.Black;

			foreach(var colorArray in mixture)
			{
				foreach(var color in colorArray)
				{
					combo |= color;
				}
			}

			return combo;
		}

		public static Int32 NegateInt32(ref Int32 num)
		{
			return num = -num;
		}
    }
}
