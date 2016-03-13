using System;
using System.Diagnostics;
using OpenTK;

namespace fastmath
{
    class MainClass
    {
        public unsafe static void Main (string[] args)
        {
            var sw = new Stopwatch ();

            Matrix4 left = new Matrix4(new Vector4(0.5f, 0, 0.1f, 0), Vector4.UnitX, Vector4.UnitY, Vector4.UnitW);
            Matrix4 right = Matrix4.Identity;
            Matrix4 o = Matrix4.Zero;

            const int ITERATIONS = 10000000;

            //Warm up
            Matrix4.Mult (ref left, ref right, out o);
            Matrix4.Mult (ref left, ref right, out o);
            Matrix4.Mult (ref left, ref right, out o);

            sw.Start ();
            for (int i=0; i<ITERATIONS; ++i)
            {
                Matrix4.Mult (ref left, ref right, out o);
            }
            sw.Stop ();
            Console.WriteLine ("Normal mult: {0}ms", sw.ElapsedMilliseconds);
            sw.Reset ();
            Console.WriteLine (o);

            //warm up
            FastMath.NativeMult (ref left, ref right, out o);
            FastMath.NativeMult (ref left, ref right, out o);
            FastMath.NativeMult (ref left, ref right, out o);

            sw.Start ();
            for (int i=0; i<ITERATIONS; ++i)
            {
                FastMath.NativeMult (ref left, ref right, out o);
            }
            sw.Stop ();
            Console.WriteLine ("Native mult: {0}ms", sw.ElapsedMilliseconds);
            sw.Reset ();
            Console.WriteLine (o);



            sw.Start ();

            for (int i=0; i<ITERATIONS; ++i)
            {
                FastMath.NativePtrMult (&left, &right, &o);
            }
            sw.Stop ();
            Console.WriteLine ("Native mult: {0}ms", sw.ElapsedMilliseconds);
            sw.Reset ();
            Console.WriteLine (o);
        }
    }
}
