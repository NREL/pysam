import PySAM.CustomGeneration as custom

from .HybridBase import HybridGenerator

class CustomGenerationHybrid(HybridGenerator):
    """
    Class that adds CustomGeneration to HybridSystem
    """
    def __init__(self) -> None:
        super().__init__(custom, "custom_generation")
        self._data : custom.CustomGeneration