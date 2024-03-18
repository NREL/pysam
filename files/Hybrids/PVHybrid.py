import PySAM.Pvsamv1 as pv

from .HybridBase import HybridGenerator

class PVHybrid(HybridGenerator):
    """
    Class that adds Pvsamv1 to HybridSystem
    """
    def __init__(self, name="pvsamv1") -> None:
        super().__init__(pv, name)
        self._data: pv.Pvsamv1