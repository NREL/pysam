import PySAM.GenericSystem as gensys

from .HybridBase import HybridGenerator

class GenericSystemHybrid(HybridGenerator):
    """
    Class that adds GenericSystem to HybridSystem
    """
    def __init__(self, name="generic_system") -> None:
        super().__init__(gensys, name)
        self._data : gensys.GenericSystem