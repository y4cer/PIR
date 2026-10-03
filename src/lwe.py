from sage.all import *
from sage.probability.probability_distribution import ProbabilityDistribution


class LWE:
    m: Integer
    p: Integer
    n: Integer
    xi: ProbabilityDistribution

    def __init__(
        self,
        n: Integer,     # security parameter
        m: Integer,
        p: Integer,
        xi: ProbabilityDistribution,
    ):  
        self.n = n
        self.m = m
        self.p = p
        self.xi = xi


    def gen_private_key(self):
        k = GF(self.p)
        private_key = [k.random_element() for _ in range(self.n)]

        return private_key


    def public_key(self):
        pass
