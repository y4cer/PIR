from sage.all import *
from sage.probability.probability_distribution import ProbabilityDistribution


class LWE:
    m: Integer
    p: Integer
    xi: ProbabilityDistribution

    def __init__(self, m: Integer, p: Integer, xi: ProbabilityDistribution):
        self.m = m
        self.p = p
        self.xi = xi

    def gen_key(self):
        pass
