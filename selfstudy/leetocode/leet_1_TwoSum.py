class Solution:
    def twoSum(self, nums:list[int], target: int) -> list[int]:
        # Complexidade O(n) ?
        i:int = 0
        a:int = 1
        while i < len(nums):
            while a < len(nums):
                print(f"{nums[i]} + {nums[a]} = {nums[i] + nums[a]}")
                if nums[i] + nums[a] == target:
                    return [i,a]
                a += 1
            i += 1
            a = i+1
        return []


if __name__ == "__main__":
    # 1. Instancia a classe Solution
    solucao = Solution()

    # 2. Define os dados de teste
    lista = [0,1,2,3]
    alvo = 5

    # 3. Chama o método passando os argumentos necessários
    resultado:list[int] = solucao.twoSum(lista, alvo)
    print(f"Índices encontrados: {resultado}")  # Saída esperada: [0, 1]
