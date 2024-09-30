class AllOne:
    def __init__(self):
        self.myDict = {}  
        self.countDict = {}  
        self.minVal = None
        self.maxVal = None

    def _updateMinMax(self):
        if not self.myDict:
            self.minVal = self.maxVal = None
        else:
            self.minVal = min(self.myDict.values())
            self.maxVal = max(self.myDict.values())

    def inc(self, key: str) -> None:
        if key in self.myDict:
            oldCount = self.myDict[key]
            newCount = oldCount + 1
            self.myDict[key] = newCount
            self.countDict[oldCount].remove(key)
            if not self.countDict[oldCount]:
                del self.countDict[oldCount]
        else:
            newCount = 1
            self.myDict[key] = newCount

        if newCount not in self.countDict:
            self.countDict[newCount] = set()
        self.countDict[newCount].add(key)

        self._updateMinMax()

    def dec(self, key: str) -> None:
        if key not in self.myDict:
            return

        oldCount = self.myDict[key]
        newCount = oldCount - 1
        self.myDict[key] = newCount

        self.countDict[oldCount].remove(key)
        if not self.countDict[oldCount]:
            del self.countDict[oldCount]

        if newCount == 0:
            del self.myDict[key]
        else:
            if newCount not in self.countDict:
                self.countDict[newCount] = set()
            self.countDict[newCount].add(key)

        self._updateMinMax()

    def getMaxKey(self) -> str:
        if not self.myDict:
            return ""
        maxKeys = self.countDict.get(self.maxVal, set())
        return next(iter(maxKeys)) if maxKeys else ""

    def getMinKey(self) -> str:
        if not self.myDict:
            return ""
        minKeys = self.countDict.get(self.minVal, set())
        return next(iter(minKeys)) if minKeys else ""
