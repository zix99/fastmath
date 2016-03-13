using System;
using System.Runtime.InteropServices;
using OpenTK;

namespace fastmath
{
    public unsafe static class FastMath
    {
        [DllImport("libmath.dll", EntryPoint = "Mult4x4", CallingConvention = CallingConvention.Cdecl)]
        public static extern void NativeMult (
            [In] ref Matrix4 left,
            [In] ref Matrix4 right,
            [Out] out Matrix4 o);

        public delegate void MatrixMultDlg (ref Matrix4 left, ref Matrix4 right, out Matrix4 o);

        public static readonly MatrixMultDlg Mult;

        static FastMath()
        {
            Mult = NativeMult;
            //Mult = Matrix4.Mult;
        }

        /*public static void Mult(ref Matrix4 left, ref Matrix4 right, ref Matrix4 o)
        {
            /*fixed(float* ptLeft = &left.Row0.X)
            fixed(float *ptRight = &right.Row0.X)
            fixed(float* ptO = &o.Row0.X)
            {
                Mult (ptLeft, ptRight, ptO);
            }

            //Mult (&left, &right, &o);
        }*/
    }
}

