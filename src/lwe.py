from sage.all import *
from sage.probability.probability_distribution import ProbabilityDistribution
from sage.rings.finite_rings.integer_mod import IntegerMod


class LWE:
    m: Integer
    p: Integer
    xi: ProbabilityDistribution

    def __init__(
        self,
        n: Integer,     # security parameter
        m: Integer,
        p: Integer,
        xi: ProbabilityDistribution,
    ):
        self.m = m
        self.p = p
        self.xi = xi

    def gen_key(self):
        R = IntegerMod(self.p)
