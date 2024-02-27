import PySAM.Pvsamv1 as pv

from .HybridBase import HybridGenerator

class PVHybrid(HybridGenerator):
    def __init__(self, name="pvsamv1") -> None:
        super().__init__(pv, name)
        self._data: pv.Pvsamv1